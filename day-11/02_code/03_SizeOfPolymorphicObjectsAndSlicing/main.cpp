#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

#include <string>


int main()
{

    std::string name("");

    std::cout << sizeof(name) << std::endl; // 32

    // Comparing object sizes
    std::cout << "sizeof(Shape) : " << sizeof(Shape) << std::endl;   // dynamic : 40
    std::cout << "sizeof(Oval) : " << sizeof(Oval) << std::endl;     // dynamic : 56
    // here the size is 56 is because Oval has 2 double members (8 bytes each) + Shape part (40 bytes) = 56 bytes
    std::cout << "sizeof(Circle) : " << sizeof(Circle) << std::endl; // dynamic : 56
    // here the size is 56 is because Circle has no new members of its own + Oval part (56 bytes) = 56 bytes

    // Slicing
    Circle circle1(3.3, "Circle1");
    Shape shape = circle1;
    shape.draw(); // Shape::draw

    return 0;
}