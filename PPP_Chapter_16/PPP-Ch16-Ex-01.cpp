//main.cpp
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


int main()
try
{
    // Window
    Point tl{ 100, 100 };
    My_window win{ tl,600,400,"lines" };
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
