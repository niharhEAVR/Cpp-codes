#include <iostream>
#include "child.h"

int main()
{
    Child c1(33);
    c1.print_var();         // Calls the method in Child
    c1.Parent::print_var(); // Calls the method in Parent,
                            // value in parent just contains junk or whatever
                            // in class initialization we did.

    std::cout << "--------" << std::endl;
    c1.show_values();
    return 0;
}