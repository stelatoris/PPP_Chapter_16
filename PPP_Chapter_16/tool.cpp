// tools.cpp
// Programming: Principles and Practices using c++ - Bjarne Stroustrup
// 
// Chapter 16 Drill and Exercise solutions

#include "Simple_window.h"
#include "tools.h"
#include <math.h>
using namespace std;

using namespace Graph_lib;

//----------------------------------------------------------------------
// 16.5 An Example

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
	menu_button{Point{x_max() - 80,30},80,20,"tool menu",cb_menu}
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

//----------------------------------------------------------------------
//  1. Make a My_window that’s a bit like Simple_window except that it has
//     two buttons, nextand quit.

My_window::My_window(Point xy, int w, int h, const string& title)
	: Window{ xy,w,h,title },
	next_button{ Point{x_max() - 150,0},70,20,"Next point", cb_next },
	quit_button{ Point{x_max() - 70,0},70,20,"Quit", cb_quit }
{
	attach(next_button);
	attach(quit_button);
}

void My_window::cb_next(Address, Address pw)
{
	reference_to<My_window>(pw).next();
}

void My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void My_window::quit()
{
	hide();
}

void My_window::next()
{
	redraw();
}