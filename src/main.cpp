// Build:  g++ -std=c++17 main.cpp -o demo $(fltk-config --cxxflags --ldflags)
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <cstdio>
#include <vector>
#include "Components/CardScroll.hpp"

using namespace ui;

static void onRegister(Fl_Widget *, void *card)
{
    std::printf("Clicked: %s\n", static_cast<EventCard *>(card)->data().title.c_str());
}

int main()
{
    // your info, e.g. loaded from a file / API / database
    std::vector<EventData> events(10);
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
    events[5] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};
    events[6] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};

    events[7] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};
    events[8] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};
    events[9] = {"ITC Career Guidance Cell", "Career Networking", "May 29",
                 "ITC Career Fair 2025: Engineering Meet", "",
                 "10:00 - 16:00", "Main Hall", "28 tech & engineering partners attending",
                 "Register", "Open Access", 0xE0E3F3, 0x374151, 0, 0, ButtonStyle::Soft};

    Fl_Window *win = new Fl_Window(1280, 920, "Events");
    CardScroll *scroll = new CardScroll(0, 120, 440, 750);
    CardScroll *scroll1 = new CardScroll(440, 120, 440, 750); // x, y, w, MAX height
    CardScroll *scroll2 = new CardScroll((440 + 20) * 2 - 40, 120, 400, 750);
    win->color(fl_rgb_color(0xEE, 0xF0, 0xFF));
    for (const EventData &e : events)
    { // your loop
        EventCard *card = scroll->addCard(e);
        EventCard *card1 = scroll1->addCard(e);
        EventCard *card2 = scroll2->addCard(e);
        card->button()->callback(onRegister, card);
    }

    win->end();
    win->show();
    int rc = Fl::run();
    delete win;
    return rc;
}
