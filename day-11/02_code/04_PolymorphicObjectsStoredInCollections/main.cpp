#include <iostream>
#include <memory>
#include "shape.h"
#include "oval.h"
#include "circle.h"

int main()
{

    Circle circle1(7.2, "circle1");
    Oval oval1(13.3, 1.2, "Oval1");
    Circle circle2(11.2, "circle2");
    Oval oval2(31.3, 15.2, "Oval2");
    Circle circle3(12.2, "circle3");
    Oval oval3(53.3, 9.2, "Oval3");

    // If you store raw object data in an array set up to store base class objects
    // the data is going to be sliced off!
    std::cout << "sizeof (circle1) : " << sizeof(circle1) << std::endl;
    Shape shapes1[]{circle1, oval1, circle2, oval2, circle3, oval3};

    for (Shape &s : shapes1)
    {
        std::cout << "sizeof (object) : " << sizeof(s) << std::endl;
        s.draw(); // here the slicing occurs because s is a reference to the base class, so only the base class part is drawn
        std::cout << std::endl;
    }

    // What if we store in references? Compiler error : references aren't left assignable
    // const Shape &shapes2[]{circle1, oval1, circle2, oval2, circle3, oval3};
    // ARRAY OF REFERENCES IS NOT ALLOWED IN C++, because references must be initialized when they are created and cannot be reseated to refer to another object later.

    std::cout << "----------------------------------------" << std::endl;

    // Raw pointers
    Shape *shapes3[]{&circle1, &oval1, &circle2, &oval2, &circle3, &oval3};
    for (Shape *shape_ptr : shapes3)
    {
        std::cout << "Inside array , sizeof(*shape_ptr) : " << sizeof(*shape_ptr) << std::endl;
        shape_ptr->draw();
        std::cout << std::endl;
    }
    // here the size of the object pointed to by shape_ptr is determined by the static type of the pointer, which is Shape. Therefore, sizeof(*shape_ptr) will always return the size of the Shape class, regardless of the actual object type.
    // but the draw() function is virtual, so the correct derived class's draw() function is called at runtime.
    // this happening because the compiler uses the vtable (virtual table) mechanism to determine the correct function to call based on the actual object type, not the pointer type.
    // and this is because we are using pointers, so no slicing occurs.

    std::cout << "----------------------------------------" << std::endl;

    // Smart pointers
    std::shared_ptr<Shape>
        shapes4[]{std::make_shared<Circle>(12.2, "Circle4"),
                  std::make_shared<Oval>(10.0, 20.0, "Oval4")};
    for (auto &s : shapes4)
    {
        std::cout << "Inside array , sizeof(*s) : " << sizeof(*s) << std::endl;
        // doesnt matter if we use auto or std::shared_ptr<Shape> &s here the type of s is still std::shared_ptr<Shape> and thats why sizeof(*s) gives size of Shape only and not the derived class
        s->draw();
    }
    // This shared pointer array works the same way as the raw pointer array, but with automatic memory management.
    // No slicing occurs here either.

    return 0;
}