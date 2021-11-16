// tools.h

#include "Graph.h"
#include "std_lib_facilities.h"
#define PI 3.14159265

using namespace Graph_lib;

namespace Graph_lib {
  
    //----------------------------------------------------------------------
    struct Lines_window :Window {
        Lines_window(Point xy, int w, int h, const string& title);
    private:
        // data:
        Open_polyline lines;

        // widgets:
        Button next_button;
        Button quit_button;
        In_box next_x;
        In_box next_y;
        Out_box xy_out;
        Menu main_menu;
        Menu color_menu;
        Menu style_menu;
        Button menu_button;
        

        void change_c(Color c) { lines.set_color(c); }
        void change_ls(Line_style ls) { lines.set_style(ls); }

        void hide_m_menu() { main_menu.hide(); }
        void hide_color_menu() { color_menu.hide(); menu_button.show(); }
        void hide_style_menu() { style_menu.hide(); menu_button.show(); }

        // invoked by callbacks:
        void color_pressed() { main_menu.hide(); color_menu.show(); }
        void red_pressed() { change_c(Color::red); hide_color_menu(); }
        void blue_pressed() { change_c(Color::blue); hide_color_menu(); }
        void black_pressed() { change_c(Color::black); hide_color_menu(); }        

        void style_pressed(){ main_menu.hide(); style_menu.show(); }
        void dash_pressed() { change_ls(Line_style::dash); hide_style_menu(); }
        void dashdot_pressed() { change_ls(Line_style::dashdot); hide_style_menu(); }
        void dashdotdot_pressed() { change_ls(Line_style::dashdotdot); hide_style_menu(); }
        void dot_pressed() { change_ls(Line_style::dot); hide_style_menu(); }

        void m_menu_pressed() { menu_button.hide(); main_menu.show(); }

        void next();
        void quit();

        // callback functions:
        static void cb_red(Address, Address);
        static void cb_blue(Address, Address);
        static void cb_black(Address, Address);      

        static void cb_dash(Address, Address);
        static void cb_dashdot(Address, Address);
        static void cb_dashdotdot(Address, Address);
        static void cb_dot(Address, Address);

        static void cb_menu(Address, Address);
        static void cb_color(Address, Address);
        static void cb_style(Address, Address);

        static void cb_next(Address, Address);
        static void cb_quit(Address, Address);
    };

    //----------------------------------------------------------------------
    //  1. Make a My_window that’s a bit like Simple_window except that it has
    //     two buttons, nextand quit.

    struct My_window :Window {
        My_window(Point xy, int w, int h, const string& title);

    private:
        // widgets:
        Button next_button;
        Button quit_button;

        void next();
        void quit();

        // callback functions:
        static void cb_next(Address, Address);
        static void cb_quit(Address, Address);
    };

}   // end of Graph_lib namespace

