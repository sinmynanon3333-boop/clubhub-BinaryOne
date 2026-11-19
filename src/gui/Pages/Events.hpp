#pragma once
#include "D:\clubhub-BinaryOne\src\gui\Components\CardScroll.hpp"
#include <FL/Fl_Group.H>

#include <vector>
using namespace ui;
class Events : public Fl_Group {
    CardScroll* makeScroll(int x, int y, int w, int h, const std::vector<EventData>& data) {
        CardScroll* s = new CardScroll(x, y, w, h);
        for (const EventData& e : data) {
            EventCard* card = s->addCard(e);
            // card->button()->callback(onRegister, card);
        }
        return s;
    }

public:
    // W must cover all three scrolls, so pass the full width you want them in
    Events(int X, int Y, int W, int H) : Fl_Group(X, Y, W, H) {
        std::vector<EventData> events(5);
        events[0] = {"ITC Robotics Society", "Stage 2 Ready", "Tomorrow",
                 "AI & Computer Vision Workshop",
                 "Hands-on YOLOv8 deployment on embedded NVIDIA Jetson platforms.",
                 "14:00 - 16:30", "Lab 402", "Fast-track QR generated on RSVP",
                 "Register Now", "", 0x86EFAC, 0x166534, 42, 50, ButtonStyle::Primary};
    events[1] = {"GDG Campus Chapter", "Free Entry", "May 26",
                 "Next.js 15 Fullstack Bootcamp",
                 "Server Actions, Turbopack, and edge caching architecture patterns.",
                 "09:00 - 12:00", "Auditorium A", "40 spots open | Instant confirmation",
                 "RSVP Free", "", 0xDBEAFE, 0x1D4ED8, 110, 150, ButtonStyle::Positive};
    events[2] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};
     events[3] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};
     events[4] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};             

        const int gap = 10;
        const int cw  = (W - 2 * gap) / 3;      // width of each scroll

        for (int i = 0; i < 3; i++)
            makeScroll(X + i * (cw + gap), Y, cw, H, events);
        end();                                  // important
    }
};