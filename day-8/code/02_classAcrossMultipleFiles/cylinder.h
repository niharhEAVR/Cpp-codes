#pragma once
#include "constants.h"

class Cylinder
{
public:
    Cylinder() = default;
    Cylinder(double rad_param, double height_param);
    double volume();

    double get_base_radius();
    double get_height();

    void set_base_radius(double rad_param);
    void set_height(double height_param);

private:
    double base_radius{1};
    double height{1};
};
