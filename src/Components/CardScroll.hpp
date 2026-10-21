#pragma once
// CardScroll.hpp - outer container: a scroll with no scrollbar UI.
// Its height grows with the cards but never goes past maxH (your parameter).
// The mouse wheel scrolls it and it stops exactly at the last card.

#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Box.H>
#include <algorithm>
#include "EventCard.hpp"

namespace ui {

class CardScroll : public Fl_Scroll {
public:
    // maxH = the most height this scroll may take. pad/gap are in pixels.
    CardScroll(int X, int Y, int W, int maxH, int pad = 12, int gap = 12)
        : Fl_Scroll(X, Y, W, 0), maxH_(maxH), pad_(pad), gap_(gap) {
        this->type(0);                            // 0 = never show scrollbars
        this->box(FL_RFLAT_BOX);
        color(rgb(0xF4F5FB));
        // Invisible 1px anchor at the top-left. Fl_Scroll measures its scroll
        // position from the bounding box of its children, so without this the
        // padding above the first card counts as an offset and the content jumps.
        new Fl_Box(X, Y, 1, 1);
        end();
        nextY_ = pad_;
        contentH_ = 2 * pad_;
        size(W, std::min(contentH_, maxH_));
    }


    // Build one card from the data and stack it under the previous one.
    EventCard* addCard(const EventData& d) {
        Fl_Group* prev = Fl_Group::current();   // don't disturb the caller's group
        begin();
        EventCard* card = new EventCard(x() + pad_, y() - yposition() + nextY_,
                                        w() - 2 * pad_, d);
        end();
        Fl_Group::current(prev);

        nextY_ += card->h() + gap_;
        contentH_ = nextY_ - gap_ + pad_;       // ends at the last card (+ pad)
        size(w(), std::min(contentH_, limitH()));  // grow until the limit
        if (parent()) parent()->redraw();
        return card;
    }

    int handle(int e) override {
        if (e == FL_MOUSEWHEEL) {               // before the children see it
            int newY = std::clamp(yposition() + Fl::event_dy() * 30, 0, maxScrollY());
            if (newY != yposition()) scroll_to(xposition(), newY);
            return 1;
        }
        return Fl_Scroll::handle(e);
    }

    int maxScrollY() const { return std::max(0, contentH_ - h()); }

private:
    // maxH, but never taller than the space left inside the parent window,
    // so the scroll can't stick out past the window edge.
    int limitH() const {
        if (!parent()) return maxH_;
        return std::min(maxH_, std::max(1, parent()->y() + parent()->h() - y()));
    }

    int maxH_, pad_, gap_;
    int nextY_ = 0;      // next free y from the top of the content
    int contentH_ = 0;   // total content height
};

} // namespace ui