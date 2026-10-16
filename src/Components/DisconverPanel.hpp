#pragma once
// DiscoverPanel.hpp - the outer container: header, search, chips, event cards.
// It is an Fl_Scroll with NO scrollbars (type 0). The mouse wheel scrolls it and
// scrolling stops exactly at the bottom edge of the last card.

#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <algorithm>
#include <string>
#include <vector>
#include "EventCard.hpp"

namespace ui {

// Fl_Input with fake placeholder text (FLTK has none built in)
class HintInput : public Fl_Input {
public:
    HintInput(int X, int Y, int W, int H, const std::string& hint)
        : Fl_Input(X, Y, W, H), hint_(hint) {
        showHint();
    }
    int handle(int e) override {
        if (e == FL_FOCUS && showing_) {
            value("");
            textcolor(rgb(0x1B1F3B));
            showing_ = false;
        } else if (e == FL_UNFOCUS && size() == 0) {
            showHint();
        }
        return Fl_Input::handle(e);
    }
    std::string text() const { return showing_ ? "" : std::string(value()); }

private:
    void showHint() {
        value(hint_.c_str());
        textcolor(rgb(0x7C84A6));
        showing_ = true;
        redraw();
    }
    std::string hint_;
    bool showing_ = true;
};

class DiscoverPanel : public Fl_Scroll {
public:
    DiscoverPanel(int X, int Y, int W, int H) : Fl_Scroll(X, Y, W, H) {
        type(0);                                    // 0 = never show scrollbars
        box(FL_FLAT_BOX);
        color(rgb(0xF4F5FB));

        const int cw = W - 2 * PAD;
        int cy = PAD;

        // header: dot  title ............ "N Available"
        Fl_Box* dot = new Fl_Box(X + PAD, Y + cy + 10, 8, 8);
        dot->box(FL_OVAL_BOX);
        dot->color(rgb(0x1D4ED8));

        makeText(X + PAD + 18, Y + cy, cw - 18 - 110, 28, "Discover & Register",
                 17, 0x1B1F3B, true);
        countLabel_ = makeText(X + W - PAD - 110, Y + cy, 110, 28, "0 Available",
                               11, 0x1D4ED8, true, FL_ALIGN_RIGHT);
        cy += 38;

        // search bar: rounded background + inset input
        Fl_Box* bg = new Fl_Box(X + PAD, Y + cy, cw, 34);
        bg->box(FL_RFLAT_BOX);
        bg->color(rgb(0xE8EBF9));
        search_ = new HintInput(X + PAD + 12, Y + cy + 5, cw - 24, 24,
                                "Filter by club, tech stack, lab room...");
        search_->box(FL_FLAT_BOX);
        search_->color(rgb(0xE8EBF9));
        search_->textsize(12);
        cy += 34 + 10;

        // filter chips (wrap onto a new row if they don't fit)
        const char* names[] = {"All Disciplines", "Robotics", "Fullstack Dev",
                               "Career", "Cybersecurity"};
        int cx = PAD;
        for (const char* n : names) {
            int chipW = textWidth(n, FL_HELVETICA, 11) + 24;
            if (cx + chipW > W - PAD) {             // wrap
                cx = PAD;
                cy += 30;
            }
            Fl_Button* chip = new Fl_Button(X + cx, Y + cy, chipW, 24);
            chip->copy_label(esc(n).c_str());
            chip->box(FL_RFLAT_BOX);
            chip->down_box(FL_RFLAT_BOX);
            chip->labelsize(11);
            chip->clear_visible_focus();
            chip->callback(onChip, this);
            chips_.push_back(chip);
            cx += chipW + 6;
        }
        selectChip(chips_.front());
        cy += 24 + 14;

        end();                                      // stop adding to this group

        nextY_ = cy;                                // where the first card goes
        contentH_ = cy + PAD;
    }

    // Add a card under the previous one. Returns the pointer so you can
    // attach a callback to card->button().
    EventCard* addCard(const EventData& d) {
        Fl_Group* prev = Fl_Group::current();       // keep the caller's group intact
        begin();
        EventCard* card = new EventCard(x() + PAD, y() - yposition() + nextY_,
                                        w() - 2 * PAD, d);
        end();
        Fl_Group::current(prev);

        nextY_ += card->h() + GAP;
        contentH_ = nextY_ - GAP + PAD;             // ends at the last card (+ padding)
        ++cardCount_;
        std::string t = std::to_string(cardCount_) + " Available";
        countLabel_->copy_label(t.c_str());
        redraw();
        return card;
    }

    int handle(int e) override {
        if (e == FL_MOUSEWHEEL) {                   // intercept BEFORE children see it
            scrollBy(Fl::event_dy() * 30);
            return 1;
        }
        return Fl_Scroll::handle(e);
    }

    void scrollBy(int dy) {
        int newY = std::clamp(yposition() + dy, 0, maxScrollY());
        if (newY != yposition()) scroll_to(xposition(), newY);
    }

    int maxScrollY() const { return std::max(0, contentH_ - h()); }
    std::string searchText() const { return search_->text(); }

private:
    static constexpr int PAD = 14;
    static constexpr int GAP = 12;

    static void onChip(Fl_Widget* w, void* self) {
        static_cast<DiscoverPanel*>(self)->selectChip(w);
    }

    void selectChip(Fl_Widget* active) {
        for (Fl_Button* c : chips_) {
            bool on = (c == active);
            c->color(on ? rgb(0x1E40AF) : rgb(0xFFFFFF));
            c->labelcolor(on ? FL_WHITE : rgb(0x374151));
            c->redraw();
        }
    }

    Fl_Box* countLabel_ = nullptr;
    HintInput* search_ = nullptr;
    std::vector<Fl_Button*> chips_;
    int nextY_ = 0;         // next free y, measured from the top of the content
    int contentH_ = 0;      // total content height (top of panel -> last card + PAD)
    int cardCount_ = 0;
};

} // namespace ui