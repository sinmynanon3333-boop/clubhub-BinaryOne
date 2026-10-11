#ifndef WELCOME_PAGE_HPP
#define WELCOME_PAGE_HPP
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Help_View.H>
class WelComePage : public Fl_Group{
    public:
        WelComePage(int x,int y,int w,int h): Fl_Group(x, y, w, h){
        Fl_Group *Welcome=new Fl_Group(0,0,w,h);
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
        image_box->color(fl_rgb_color(0xEE, 0xF0, 0xFF));
        Fl_Image *scaled_img = img->copy(img_w, img_h);
        image_box->image(scaled_img);
        Fl_Group *title = new Fl_Group(w / 2, img_y + 130, 250, 200);
        Fl_Box *txtWel = new Fl_Box(w / 2 - 155, img_y + 130, 250, 200, "Welcome to ITC student ");
        txtWel->labelsize(17);
        txtWel->labelcolor(FL_BLACK);
        Fl_Box *txtClub = new Fl_Box(w / 2 - 120, img_y + 130, 250, 200, "Club Hub");
        txtClub->labelsize(17);
        txtClub->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
        txtClub->labelcolor(FL_BLUE);
        title->end();
        Fl_Box *txtDetail = new Fl_Box(w / 2 - 137, img_y + 190, 250, 200, "The central campus life  for students of the Institute of Technology of Cambodia.\nDiscover 30+ engineering, robotic, and cultural societies, register for workshops, and \naccelerate your university journey.");
        txtDetail->labelcolor(FL_BLACK);
        txtDetail->labelsize(17);
        Fl_Button *btn = new Fl_Button(w / 2 - 75, img_y + 330, 150, 50, "Get Started  @s15@->");
        btn->box(FL_RFLAT_BOX);
        btn->color(FL_BLUE);
        btn->labelcolor(FL_WHITE);

        // card 1
        Fl_Group *card1 = new Fl_Group(w / 2 - 75 - 500, img_y + 400, 340, 200);
        card1->box(FL_RFLAT_BOX);
        card1->color(FL_WHITE);

        // 2. Create the blue icon box
        Fl_Box *icon_box1 = new Fl_Box(w / 2 - 75 + 24 - 500, img_y + 400 + 24, 47, 47);
        icon_box1->box(FL_RFLAT_BOX);
        icon_box1->color(fl_rgb_color(235, 242, 255));
        icon_box1->label("🎓");
        icon_box1->labelsize(25);
        icon_box1->labelcolor(fl_rgb_color(10, 80, 210));
        Fl_Box *Ex1 = new Fl_Box(w / 2 - 75 + 95 - 500, img_y + 480, 30, 30, "Leadership Credits");
        Ex1->labelsize(18);
        Ex1->labelfont(FL_BOLD);
        Fl_Box *text_view1 = new Fl_Box(w / 2 - 90 + 30 - 500 - 5, img_y + 525, 290, 30, "Earn verified extracurricular certifi\n-cates endorsed by ITC Faculty\nCouncil.");
        text_view1->box(FL_FLAT_BOX);
        text_view1->color(FL_WHITE);
        text_view1->labelcolor(fl_rgb_color(131, 138, 133));
        text_view1->labelsize(17);
        card1->end();

        // card 2
        Fl_Group *card2 = new Fl_Group(w / 2 - 75 - 100, img_y + 400, 340, 200);
        card2->box(FL_RFLAT_BOX);
        card2->color(FL_WHITE);

        // 2. Create the blue icon box
        Fl_Box *icon_box2 = new Fl_Box(w / 2 - 75 + 24 - 100, img_y + 400 + 24, 47, 47);
        icon_box2->box(FL_RFLAT_BOX);
        icon_box2->color(fl_rgb_color(216, 233, 223));
        icon_box2->label("☎");
        icon_box2->labelsize(25);
        icon_box2->labelcolor(fl_rgb_color(0, 110, 45));
        Fl_Box *Ex2 = new Fl_Box(w / 2 - 75 + 95 - 100 - 10, img_y + 480, 30, 30, "Events & Passes");
        Ex2->labelsize(18);
        Ex2->labelfont(FL_BOLD);
        Fl_Box *text_view2 = new Fl_Box(w / 2 - 90 + 30 - 100, img_y + 525, 290, 30, "One-click RSVP with instant student\nQR entry badges for hackathons and\ntech talks.");
        text_view2->box(FL_FLAT_BOX);
        text_view2->color(FL_WHITE);
        text_view2->labelcolor(fl_rgb_color(131, 138, 133));
        text_view2->labelsize(17);
        card2->end();
        // card 3
        Fl_Group *card = new Fl_Group(w / 2 - 75 + 300, img_y + 400, 340, 200);
        card->box(FL_RFLAT_BOX);
        card->color(FL_WHITE);

        // 2. Create the blue icon box
        Fl_Box *icon_box = new Fl_Box(w / 2 - 75 + 24 + 300, img_y + 400 + 24, 47, 47);
        icon_box->box(FL_RFLAT_BOX);
        icon_box->color(fl_rgb_color(235, 242, 255));
        icon_box->label("♣");
        icon_box->labelsize(25);
        icon_box->labelcolor(fl_rgb_color(10, 80, 210));
        Fl_Box *Ex = new Fl_Box(w / 2 - 75 + 95 + 300, img_y + 480, 30, 30, "Explore more Clubs");
        Ex->labelsize(18);
        Ex->labelfont(FL_BOLD);
        Fl_Box *text_view = new Fl_Box(w / 2 - 90 + 30 + 300, img_y + 525, 290, 30, "Robotics & AI Lab, GIC on Campus, \n Civil Eng. Build, and ITC Philanthropy \n & Arts.");
        text_view->box(FL_FLAT_BOX);
        text_view->color(FL_WHITE);
        text_view->labelcolor(fl_rgb_color(131, 138, 133));
        text_view->labelsize(17);
        card->end();
        Welcome->end();
        end();
            }


};
#endif