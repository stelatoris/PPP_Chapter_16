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
