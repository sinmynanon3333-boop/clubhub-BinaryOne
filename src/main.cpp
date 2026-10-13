#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Group.H>
#include "Pages/WelcomePage.hpp"
#include "Pages/LoginForm.hpp"
void button_cb(Fl_Widget *w, void *data)
{
    Fl_Box *label = (Fl_Box *)data;
    label->label("Button click u idiot!");
    label->redraw();
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

    StudentLoginCard *stud = new StudentLoginCard(card_x, card_y, card_w, card_h);
    // WelComePage *welcome=new WelComePage(x,y,w,h);
    window->end();
    window->show();
    return Fl::run();
}