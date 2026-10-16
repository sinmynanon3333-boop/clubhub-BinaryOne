#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
namespace header
{
    class HeaderPage : public Fl_Group
    {
    private:
        //  int cap_w = 680;
        // int cap_h = 36;
        // int cap_x = (1280 / 2) - (cap_w / 2);
        // int cap_y = 40;
    public:
        HeaderPage(int x, int y, int w, int h) : Fl_Group(x, y, w, h)
        {
            this->box(FL_RFLAT_BOX);
            this->color(FL_WHITE);
            Fl_Box *txt1 = new Fl_Box(x + 20, y, 250, h, "Institute of Technology of Cambodia (ITC)");
            txt1->labelcolor(fl_rgb_color(100, 100, 100));
            txt1->labelsize(13);
            txt1->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

            Fl_Box *txt2 = new Fl_Box(x + 275, y, 130, h, "•  OFFICIAL PORTAL  •");
            txt2->labelcolor(fl_rgb_color(20, 90, 200));
            txt2->labelfont(FL_BOLD);
            txt2->labelsize(12);

            txt2->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
            Fl_Box *txt3 = new Fl_Box(x + 410, y, 250, h, "វិទ្យាស្ថានបច្ចេកវិទ្យាកម្ពុជា");
            txt3->labelcolor(fl_rgb_color(100, 100, 100));
            txt3->labelsize(15);
            txt3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
            this->end();
        }
    };

}
