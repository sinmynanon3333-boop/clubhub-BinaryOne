#pragma once
// EventCard.hpp - the small inner container (one event card)

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Progress.H>
#include <FL/fl_draw.H>
#include <algorithm>
#include <string>

namespace ui {

// ---------- small helpers -------------------------------------------------

inline Fl_Color rgb(unsigned hex) {
    return fl_rgb_color((hex >> 16) & 255, (hex >> 8) & 255, hex & 255);
}

// '&' in an FLTK label underlines the next char, so double it
inline std::string esc(const std::string& s) {
    std::string out;
    for (char c : s) {
        if (c == '&') out += '&';
        out += c;
    }
    return out;
}

inline int textWidth(const std::string& s, Fl_Font f, int size) {
    fl_font(f, size);
    return (int)fl_width(s.c_str());
}

// Transparent text label (Fl_Box with no box type)
inline Fl_Box* makeText(int X, int Y, int W, int H, const std::string& s,
                        int size, unsigned color, bool bold = false,
                        Fl_Align a = FL_ALIGN_LEFT) {
    Fl_Box* b = new Fl_Box(X, Y, W, H);
    b->copy_label(s.c_str());               // copy_label: FLTK keeps its own copy (Fl_Box: no '&' escaping needed)
    b->labelsize(size);
    b->labelcolor(rgb(color));
    b->labelfont(bold ? FL_HELVETICA_BOLD : FL_HELVETICA);
    b->align(a | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    return b;
}

// ---------- data ----------------------------------------------------------

enum class ButtonStyle { Primary, Positive, Soft };

struct EventData {
    std::string club, badge, date, title, description;
    std::string time, location, footer, buttonText;
    std::string openLabel;              // shown on the right when capacity == 0
    unsigned badgeBg = 0xBBF7D0;        // 0xRRGGBB
    unsigned badgeFg = 0x166534;
    int filled = 0, capacity = 0;       // capacity == 0 -> no progress bar
    ButtonStyle style = ButtonStyle::Primary;
};

// ---------- the card ------------------------------------------------------

class EventCard : public Fl_Group {
public:
    // Width is given, the height is computed from the content.
    EventCard(int X, int Y, int W, const EventData& d)
        : Fl_Group(X, Y, W, 0), data_(d) {
        resizable(nullptr);                 // don't stretch children
        box(FL_RFLAT_BOX);
        color(rgb(0xE8EBFB));

        const int PAD = 12;
        const int cx = X + PAD, cw = W - 2 * PAD;
        int cy = Y + 10;

        // row 1: club | badge ................ date
        int clubW = textWidth(d.club, FL_HELVETICA_BOLD, 11) + 12;
        makeText(cx, cy, clubW, 18, d.club, 11, 0x1D4ED8, true);

        int badgeW = textWidth(d.badge, FL_HELVETICA_BOLD, 9) + 18;
        Fl_Box* badge = makeText(cx + clubW + 8, cy + 1, badgeW, 16, d.badge, 9,
                                 d.badgeFg, true, FL_ALIGN_CENTER);
        badge->box(FL_RFLAT_BOX);
        badge->color(rgb(d.badgeBg));

        int dateW = textWidth(d.date, FL_HELVETICA, 10) + 18;
        Fl_Box* date = makeText(X + W - PAD - dateW, cy, dateW, 18, d.date, 10,
                                0x4B5563, false, FL_ALIGN_CENTER);
        date->box(FL_RFLAT_BOX);
        date->color(rgb(0xD5D9EA));
        cy += 24;

        // row 2: title
        makeText(cx, cy, cw, 22, d.title, 15, 0x1B1F3B, true);
        cy += 27;

        // row 3: description (optional)
        if (!d.description.empty()) {
            makeText(cx, cy, cw, 16, d.description, 10, 0x4B5563);
            cy += 25;
        }

        // row 4: time  location ............ filled / open label
        int timeW = textWidth(d.time, FL_HELVETICA, 11) + 12;
        makeText(cx, cy, timeW, 16, d.time, 11, 0x374151);
        int locW = textWidth(d.location, FL_HELVETICA, 11) + 12;
        makeText(cx + timeW + 8, cy, locW, 16, d.location, 11, 0x374151);

        if (d.capacity > 0) {
            std::string f = std::to_string(d.filled) + " / " +
                            std::to_string(d.capacity) + " Filled";
            makeText(X + W - PAD - 130, cy, 130, 16, f, 11, 0x1D4ED8, true,
                     FL_ALIGN_RIGHT);
        } else {
            makeText(X + W - PAD - 130, cy, 130, 16, d.openLabel, 11, 0x6B7280,
                     false, FL_ALIGN_RIGHT);
        }
        cy += 22;

        // row 5: progress bar (optional)
        if (d.capacity > 0) {
            Fl_Progress* bar = new Fl_Progress(cx, cy, cw, 6);
            bar->box(FL_FLAT_BOX);              // no black border
            bar->minimum(0);
            bar->maximum((float)d.capacity);
            bar->value((float)d.filled);
            bar->color(rgb(0xCDD3F0));
            bar->selection_color(
                rgb(d.style == ButtonStyle::Positive ? 0x15803D : 0x1D4ED8));
            cy += 16;
        }

        // row 6: footer text ............ button
        int btnW = std::max(92, textWidth(d.buttonText, FL_HELVETICA_BOLD, 11) + 30);
        makeText(cx, cy, cw - btnW - 8, 28, d.footer, 10, 0x4B5563);

        btn_ = new Fl_Button(X + W - PAD - btnW, cy, btnW, 28);
        btn_->copy_label(esc(d.buttonText).c_str());
        btn_->box(FL_RFLAT_BOX);
        btn_->labelfont(FL_HELVETICA_BOLD);
        btn_->labelsize(11);
        btn_->clear_visible_focus();        // no dotted focus rectangle
        switch (d.style) {
            case ButtonStyle::Primary: btn_->color(rgb(0x1E40AF)); btn_->labelcolor(FL_WHITE); break;
            case ButtonStyle::Positive: btn_->color(rgb(0x15803D)); btn_->labelcolor(FL_WHITE); break;
            case ButtonStyle::Soft:    btn_->color(rgb(0xD0D6F2)); btn_->labelcolor(rgb(0x1B1F3B)); break;
        }
        btn_->down_box(FL_RFLAT_BOX);
        btn_->selection_color(fl_color_average(btn_->color(), FL_BLACK, 0.8f));
        cy += 28;

        size(W, cy + 10 - Y);               // card height ends at its last element
        end();
    }

    Fl_Button* button() const { return btn_; }
    const EventData& data() const { return data_; }

private:
    EventData data_;
    Fl_Button* btn_ = nullptr;
};

} // namespace ui
