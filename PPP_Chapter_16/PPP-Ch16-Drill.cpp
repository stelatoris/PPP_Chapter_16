//PPP-Ch16-Drill.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 16 Drill and Exercise solutions

#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
#include "tools.h"
#include <math.h>
#define PI 3.14159265

using namespace Graph_lib;

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

    void style_pressed() { main_menu.hide(); style_menu.show(); }
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

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	: Window{ xy,w,h,title },
	next_button{ Point{x_max() - 150,0},70,20,"Next point", cb_next },
	quit_button{ Point{x_max() - 70,0},70,20,"Quit", cb_quit },
	next_x{ Point{x_max() - 310,0},50,20,"next x:" },
	next_y{ Point{x_max() - 210,0},50,20,"next y:" },
	xy_out{ Point{100,0},100,20,"current (x,y):" },
	color_menu{ Point{x_max() - 70,40},70,20,Menu::vertical,"color" },
	style_menu{ Point{x_max() - 70,40},70,20,Menu::vertical,"style" },
	main_menu{ Point{x_max() - 70,40},70,20,Menu::vertical,"tools" },
	menu_button{ Point{x_max() - 80,30},80,20,"tool menu",cb_menu }
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no point");

	color_menu.attach(new Button{ Point{0,0},0,0,"red",cb_red });
	color_menu.attach(new Button{ Point{0,0},0,0,"blue",cb_blue });
	color_menu.attach(new Button{ Point{0,0},0,0,"black",cb_black });
	attach(color_menu);
	color_menu.hide();

	style_menu.attach(new Button{ Point{0,0},0,0,"dash",cb_dash });
	style_menu.attach(new Button{ Point{0,0},0,0,"dashdot",cb_dashdot });
	style_menu.attach(new Button{ Point{0,0},0,0,"dashdotdot",cb_dashdotdot });
	style_menu.attach(new Button{ Point{0,0},0,0,"dot",cb_dot });
	attach(style_menu);
	style_menu.hide();

	main_menu.attach(new Button{ Point{0,0},0,0,"color",cb_color });
	main_menu.attach(new Button{ Point{0,0},0,0,"style",cb_style });
	attach(main_menu);
	main_menu.hide();

	attach(menu_button);

	attach(lines);
}

void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();

	lines.add(Point{ x,y });

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}

// color  -----------------------------------
void Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}
void Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}
void Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}

// line style -----------------------------------
void Lines_window::cb_dash(Address, Address pw)
{
	reference_to<Lines_window>(pw).dash_pressed();
}

void Lines_window::cb_dashdot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dashdot_pressed();
}

void Lines_window::cb_dashdotdot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dashdotdot_pressed();
}

void Lines_window::cb_dot(Address, Address pw)
{
	reference_to<Lines_window>(pw).dot_pressed();
}

// main menu -----------------------------------
void Lines_window::cb_menu(Address, Address pw)
{
	reference_to<Lines_window>(pw).m_menu_pressed();
}

void Lines_window::cb_color(Address, Address pw)
{
	reference_to<Lines_window>(pw).color_pressed();
}

void Lines_window::cb_style(Address, Address pw)
{
	reference_to<Lines_window>(pw).style_pressed();
}

void Lines_window::cb_next(Address, Address pw)
{
	reference_to<Lines_window>(pw).next();
}

void Lines_window::cb_quit(Address, Address pw)
{
	reference_to<Lines_window>(pw).quit();
}


int main()
try
{
    // Window
    Point tl{ 100, 100 };
    Lines_window win{ tl,600,400,"lines" };
    return gui_main();
    
}

catch (std::exception& e) {
    std::cerr << "exception: " << e.what() << std::endl;
    return 1;
}
catch (...) {
    std::cerr << "exception\n";
    return 2;

}
