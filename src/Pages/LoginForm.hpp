#ifndef LOGIN_FORM_HPP
#define LOGIN_FORM_HPP

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include "Components/Header.hpp"
#define FL_HEX_COLOR(r, g, b) fl_rgb_color((r), (g), (b))
using namespace header;
class StudentLoginCard : public Fl_Group
{
private:
    // Tab Selectors
    Fl_Button *tab_student;
    Fl_Button *tab_club;
    Fl_Button *tab_organiser;
    Fl_Button *tab_admin;

    // Header Content
    Fl_Box *lbl_title;
    Fl_Box *lbl_badge;
    Fl_Box *lbl_desc;

    // Input Components (Using structured panel/entry combos)
    Fl_Input *email_input;
    Fl_Secret_Input *pass_input;
    Fl_Button *pass_forgot;

    // Selection & Submission Row Components
    Fl_Check_Button *remember_chk;
    Fl_Box *lbl_branches;
    Fl_Button *btn_submit;
    Fl_Button *lbl_activate;

public:
    StudentLoginCard(int X, int Y, int W, int H) : Fl_Group(X, Y, W, H)
    {

        // Aesthetic design values synced directly from your reference screen token palette layout
        Fl_Color bg_card = FL_HEX_COLOR(255, 255, 255);
        Fl_Color text_dark = FL_HEX_COLOR(15, 23, 42);
        Fl_Color text_muted = FL_HEX_COLOR(100, 116, 139);
        Fl_Color primary_blue = FL_HEX_COLOR(0, 82, 204);
        Fl_Color input_bg = FL_HEX_COLOR(241, 244, 250);
        Fl_Color tab_inactive = FL_HEX_COLOR(238, 242, 255);

        // Core base backing plate frame block surface setup
        this->box(FL_RFLAT_BOX);
        this->color(bg_card);
        int cap_w = 680;
        int cap_h = 36;
        int cap_x = (1280 / 2) - (cap_w / 2);
        int cap_y = 40;
        HeaderPage * header= new HeaderPage(cap_x,cap_y,cap_w,cap_h);
        // -------------------------------------------------------------
        // ROLE TABS HEADER GROUP
        // -------------------------------------------------------------
        Fl_Group *tabs = new Fl_Group(X + 15, Y + 13, 450, 60);
        tabs->color(fl_rgb_color(226, 232, 240));
        tabs->box(FL_RFLAT_BOX);
        tab_student = new Fl_Button(X + 27, Y + 20, 90, 45, "🎓 \n Student");
        tab_student->box(FL_RFLAT_BOX);
        tab_student->color(bg_card);
        tab_student->labelcolor(primary_blue);
        tab_student->labelsize(15);
        tab_student->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);

        tab_club = new Fl_Button(X + 127, Y + 20, 100, 45, "🌟 \n Club Leader");
        tab_organiser = new Fl_Button(X + 237, Y + 20, 100, 45, "  🗓️ \nOrganiser");
        tab_admin = new Fl_Button(X + 347, Y + 20, 100, 45, "  🛡️ \nAdmin");

        Fl_Button *inactive_tabs[] = {tab_club, tab_organiser, tab_admin};
        for (auto t : inactive_tabs)
        {
            t->box(FL_RFLAT_BOX);
            t->color(fl_rgb_color(226, 232, 240));
            t->labelcolor(text_muted);
            t->labelsize(15);
            t->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
        }
        tabs->end();
        // -------------------------------------------------------------
        // TITLE HEADER & TEXT SEGMENTS
        // -------------------------------------------------------------
        lbl_title = new Fl_Box(X + 20, Y + 90, 200, 30, "Student Login");
        lbl_title->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        lbl_title->labelsize(24);
        lbl_title->labelfont(FL_HELVETICA_BOLD);
        lbl_title->labelcolor(text_dark);

        lbl_badge = new Fl_Box(X + 275, Y + 93, 185, 24, "Active Student ID Required");
        lbl_badge->box(FL_RFLAT_BOX);
        lbl_badge->color(FL_HEX_COLOR(224, 231, 255));
        lbl_badge->labelcolor(primary_blue);
        lbl_badge->labelsize(11);

        lbl_desc = new Fl_Box(X + 20, Y + 125, 435, 40,"Access your club memberships, registered event QR\npasses, and campus activity");
        lbl_desc->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_WRAP);
        lbl_desc->labelsize(13);
        lbl_desc->labelcolor(text_muted);

        // -------------------------------------------------------------
        // EMAIL FIELD LOGIC STACK
        // -------------------------------------------------------------
        Fl_Box *lbl_email = new Fl_Box(X + 20, Y + 185, 300, 20, "Student ID or University Email");
        lbl_email->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        lbl_email->labelsize(13);
        lbl_email->labelfont(FL_HELVETICA_BOLD);
        lbl_email->labelcolor(text_dark);

        email_input = new Fl_Input(X + 20, Y + 210, 440, 40);
        email_input->box(FL_RFLAT_BOX); 
        email_input->color(input_bg);   
        email_input->textcolor(text_dark);
        email_input->labelsize(14);

        // -------------------------------------------------------------
        // PASSWORD FIELD LOGIC STACK
        // -------------------------------------------------------------
        Fl_Box *lbl_pass = new Fl_Box(X + 20, Y + 270, 100, 20, "Password");
        lbl_pass->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
        lbl_pass->labelsize(13);
        lbl_pass->labelfont(FL_HELVETICA_BOLD);
        lbl_pass->labelcolor(text_dark);

        pass_forgot = new Fl_Button(X + 290, Y + 270, 170, 20, "Forgot student password?");
        pass_forgot->box(FL_NO_BOX);
        pass_forgot->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
        pass_forgot->labelsize(12);
        pass_forgot->labelcolor(primary_blue);


        pass_input = new Fl_Secret_Input(X + 20, Y + 297, 440, 36);
        pass_input->box(FL_RFLAT_BOX);
        pass_input->textcolor(text_dark);
        pass_input->color(input_bg);

        // -------------------------------------------------------------
        // CREDENTIAL CHECKBOX & SUBMIT STRIP
        // -------------------------------------------------------------
        remember_chk = new Fl_Check_Button(X + 20, Y + 355, 220, 20, "Remember my student credentials");
        remember_chk->labelsize(13);
        remember_chk->labelcolor(text_muted);

        lbl_branches = new Fl_Box(X + 315, Y + 355, 145, 20, "GIC / IIC / GEE / GCI");
        lbl_branches->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
        lbl_branches->labelsize(12);
        lbl_branches->labelcolor(text_muted);

        btn_submit = new Fl_Button(X + 20, Y + 390, 440, 45, "Sign In as Student  @->");
        btn_submit->box(FL_RFLAT_BOX);
        btn_submit->color(primary_blue);
        btn_submit->labelcolor(bg_card);
        btn_submit->labelfont(FL_HELVETICA_BOLD);
        btn_submit->labelsize(15);

        lbl_activate = new Fl_Button(X + 95, Y + 455, 290, 20, "New ITC student? Activate University Account");
        lbl_activate->box(FL_NO_BOX);
        lbl_activate->labelsize(13);
        lbl_activate->labelcolor(primary_blue);


        this->end(); 
    }

    // Public getters to cleanly expose internal field contents safely outside the group object layout
    const char *get_email() const { return email_input->value(); }
    const char *get_password() const { return pass_input->value(); }
    void set_submit_callback(Fl_Callback *cb, void *p = nullptr)
    {
        btn_submit->callback(cb, p);
    }
};
#endif
