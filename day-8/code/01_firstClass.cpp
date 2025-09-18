#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder
{

public:
    //  Publically accessable member var
    double height{};

    Cylinder() = default;

    Cylinder(double rad_param, double height_param)
    {
        base_radius = rad_param;
        height = height_param;
    }

    // Functions (or methods)
    double volume()
    {
        return PI * base_radius * base_radius * height;
    }

    // getter for private member
    void get_base_radius()
    {
        std::cout << base_radius << std::endl;
    }

    // setter for private member
    void set_base_radius(double rad_param)
    {
        base_radius = rad_param;
    }

private:
    // Private member var, can't access directly by objects
    double base_radius{};
};

int main()
{

    Cylinder cylinder1; // Objects
    std::cout << "volume of c1: " << cylinder1.volume() << std::endl;

    // Change the public member variables
    cylinder1.height = 3;
    std::cout << "volume of c1: " << cylinder1.volume() << std::endl;

    Cylinder cylinder2(1, 1);
    std::cout << "volume of c2: " << cylinder2.volume() << std::endl;

    Cylinder cylinder3;
    cylinder3.set_base_radius(100);
    cylinder3.get_base_radius();

    return 0;
}