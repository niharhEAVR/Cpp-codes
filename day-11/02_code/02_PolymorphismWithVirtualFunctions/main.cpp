#include <iostream>
#include "shape.h"
#include "oval.h"
#include "circle.h"

void draw_shape(Shape *s)
{
    s->draw();
}

void draw_shape_v1(const Shape &s_r)
{
    s_r.draw();
}

int main()
{

    Shape shape1("Shape1");
    Oval oval1(2.0, 3.5, "Oval1");
    Circle circle1(3.3, "Circle1");

    // Base pointers
    Shape *shape_ptr = &shape1;
    shape_ptr->draw(); // Shape::draw

    shape_ptr = &oval1;
    shape_ptr->draw(); // Oval::draw()

    shape_ptr = &circle1;
    shape_ptr->draw(); // Circle::draw()

    // Base references
    Shape &shape_ref = circle1;
    shape_ref.draw(); // Cicle::draw()

    // Drawing shapes
    draw_shape(&circle1);
    draw_shape_v1(circle1);

    // Raw pointers
    shape_ptr = &oval1;
    // shape_ptr->get_x_rad();
    // this is not possible as base class pointer cannot access derived class members because base class is not aware of derived class members
    // here the base class is Shape and derived class is Oval

    // Shapes stored in collections
    Shape *shape_collection[]{&shape1, &oval1, &circle1};

    for (Shape *s_ptr : shape_collection)
    {
        s_ptr->draw();
    }

    return 0;
}