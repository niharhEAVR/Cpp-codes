#include <iostream>
#include "header.h"

int count = 10; // ✅ Only define once

void sayHello()
{
    std::cout << "Hello from file1!" << std::endl;
}

void maxValue(int a, int b, int c)
{
    if (a > b)
        if (a > c)
            std::cout << a << std::endl;
        else
            std::cout << c << std::endl;

    else 
        if (b > c)
            std::cout << b << std::endl;
        else
            std::cout << c << std::endl;
}