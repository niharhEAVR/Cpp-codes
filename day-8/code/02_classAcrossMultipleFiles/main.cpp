#include <iostream>
#include "constants.h"
#include "cylinder.h"

int main()
{
    Cylinder cylinder(10, 10);
    std::cout << "volume : " << cylinder.volume() << std::endl;

    std::cout << PI << std::endl;
    return 0;
}

/*
to compile the code run:

cd .\day-8\code\03_classAcrossMultipleFiles

g++ main.cpp cylinder.cpp -o name

.\name.exe

*/