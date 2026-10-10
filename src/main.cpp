#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
void button_cb(Fl_Widget *w, void *data)
{
    Fl_Box *label = (Fl_Box *)data;
    label->label("Button click u idiot!");
    label->redraw();
}

int main()
{
    int x, y, w = 1280, h = 920;
    int temp1, temp2;
    Fl::screen_xywh(x, y, temp1, temp2);
    Fl_Window *window = new Fl_Window(x, y, w, h - 60, "ITC App");
    window->color(fl_rgb_color(0xEE, 0xF0, 0xFF));

    int cap_w = 680;
    int cap_h = 36;
    int cap_x = (w / 2) - (cap_w / 2);
    int cap_y = 40;
    Fl_Group *capsule = new Fl_Group(cap_x, cap_y, cap_w, cap_h);
    capsule->box(FL_RFLAT_BOX);
    capsule->color(FL_WHITE);
    Fl_Box *txt1 = new Fl_Box(cap_x + 20, cap_y, 250, cap_h, "Institute of Technology of Cambodia (ITC)");
    txt1->labelcolor(fl_rgb_color(100, 100, 100));
    txt1->labelsize(13);
    txt1->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    Fl_Box *txt2 = new Fl_Box(cap_x + 275, cap_y, 130, cap_h, "•  OFFICIAL PORTAL  •");
    txt2->labelcolor(fl_rgb_color(20, 90, 200));
    txt2->labelfont(FL_BOLD);
    txt2->labelsize(12);

    txt2->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    Fl_Box *txt3 = new Fl_Box(cap_x + 410, cap_y, 250, cap_h, "វិទ្យាស្ថានបច្ចេកវិទ្យាកម្ពុជា");
    txt3->labelcolor(fl_rgb_color(100, 100, 100));
    txt3->labelsize(13);
    txt3->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    capsule->end();
    Fl_PNG_Image *img = new Fl_PNG_Image("D:/clubhub-BinaryOne/Institute_of_Technology_of_Cambodia_logo.png");
    int img_w = 200;
    int img_h = 200;
    int img_x = (w / 2) - (img_w / 2);
    int img_y = (h / 4) - (img_h / 2);

    Fl_Box *image_box = new Fl_Box(img_x, img_y, img_w, img_h);
    image_box->box(FL_FLAT_BOX);
    image_box->color(window->color());
    Fl_Image *scaled_img = img->copy(img_w, img_h);
    image_box->image(scaled_img);
    Fl_Box *txtWel = new Fl_Box(w / 2 - 125, img_y + 130, 250, 200, "Welcome to ITC student Club");
    txtWel->labelsize(17);
    txtWel->labelcolor(FL_BLACK);
    // Fl_Button *btn = new Fl_Button(110, 100, 120, 40, "Click me");
    // btn->callback(button_cb);

    window->end();
    window->show();
    return Fl::run();
}