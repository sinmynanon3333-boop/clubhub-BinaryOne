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
    Fl::visible_focus(0);
    int x, y, w = 1280, h = 920;
    int temp1, temp2;
    Fl::screen_xywh(x, y, temp1, temp2);
    int win_w = w;
    int win_h = h - 60; 
    Fl_Window *window = new Fl_Window(x, y, win_w, win_h, "ITC App");
    window->color(fl_rgb_color(0xEE, 0xF0, 0xFF));
    
    int card_w = 480; 
    int card_h = 520;

    int card_x = (win_w - card_w) / 2;
    int card_y = (win_h - card_h) / 2;

    // StudentLoginCard *stud = new StudentLoginCard(card_x, card_y, card_w, card_h);
    // WelComePage *welcome=new WelComePage(x,y,w,h);
    window->end();
    window->show();
    return Fl::run();
}