#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_circle(const Circle &circle)
{
    circle.draw(); // Circle::draw() called. Drawing Circle1 with radius : 3.3
}

void draw_oval(const Oval &oval)
{
    oval.draw(); // Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
}

int main()
{

    Shape shape1("Shape1");
    shape1.draw(); // Shape::draw() called. Drawing Shape1

    Oval oval1(2.0, 3.5, "Oval1");
    oval1.draw(); // Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5

    Circle circle1(3.3, "Circle1");
    circle1.draw(); // Circle::draw() called. Drawing Circle1 with radius : 3.3

    // Base pointers
    Shape *shape_ptr = &shape1;
    shape_ptr->draw(); // Shape::draw() called. Drawing Shape1
    // as you expected that normal spape will print the shape but 

    shape_ptr = &oval1;
    shape_ptr->draw(); // Shape::draw() called. Drawing Oval1
    // here you noticed that this is also printing normal oval shape 
    // that is because we user shape_ptr as Shape class, if we do this

    Oval *shape_ptr2 = &oval1;
    shape_ptr2->draw(); // Oval::draw() called. Drawing Oval1 with m_x_radius : 2 and m_y_radius : 3.5
    // now you see that the printing is correct

    shape_ptr2 = &circle1;
    shape_ptr2->draw(); // Oval::draw() called. Drawing Circle1 with m_x_radius : 3.3 and m_y_radius : 3.3

    // Base references
    Shape &shape_ref = circle1;
    shape_ref.draw(); // Shape::draw() called. Drawing Circle1

    // Drawing shapes
    draw_circle(circle1);
    draw_oval(oval1);

    // Shapes stored in collections
    Circle circle_collection[]{circle1, Circle(10.0, "Circle2"), Circle(20.0, "Circle3")};
    Oval oval_collection[]{oval1, Oval(22.3, 51.1, "Oval2")};
    // More arrays as you have more shape types, 100? Messy right?

    return 0;
}