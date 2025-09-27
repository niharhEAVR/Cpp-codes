#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main()
{

    /*
        Shape * shape_ptr = new Circle(10,"Circle1");
        shape_ptr->draw(45,"Red");
        delete shape_ptr;
    */
    // Here the problem is that the base class pointer is not able to call the derived class's draw function
    // Here the base class is shape and the derived class is circle and we wants to access the draw funtion of Oval class

    Oval *shape_ptr2 = new Circle(10, "Circle2");
    shape_ptr2->draw(45, "Green");
    delete shape_ptr2;
    // Here we are able to access the draw function of Oval class because the pointer is of type Oval

    std::cout << "=====-------------------=====" << std::endl;


    Circle circle1(7.5, "Circle1");
    Oval oval1(5.0, 3.0, "Oval1");

    std::cout << "===== Overriding Example =====" << std::endl;
    // Overriding: Circle::draw() overrides Oval::draw() and Shape::draw()
    Shape *shape_ptr = &circle1;
    shape_ptr->draw(); // Circle::draw() called -> runtime polymorphism
    shape_ptr = &oval1;
    shape_ptr->draw(); // Oval::draw() called -> runtime polymorphism

    std::cout << "\n===== Overloading Example =====" << std::endl;
    // Overloading: multiple functions with same name, different parameters
    shape_ptr = &oval1;
    shape_ptr->draw(24); // Calls Shape::draw(int) -> static type is Shape*
    // shape_ptr->draw(24, "Red");   // ❌ Error: Shape* sees only Shape members
    oval1.draw(32, "Blue"); // Calls Oval::draw(int, string) -> overload

    std::cout << "\n===== Hiding Example =====" << std::endl;
    // Hiding: Derived class function hides base class functions of same name
    Circle circle2(10.0, "Circle2");

    circle2.draw(); // Calls Circle::draw() -> overrides Oval::draw()
    // circle2.draw(16);  // ❌ Error! Circle hides Shape::draw(int)
    circle2.Oval::draw(16, "Green"); // Access hidden base function explicitly

    return 0;
}