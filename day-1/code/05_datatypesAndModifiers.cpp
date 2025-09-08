#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "--------------int----------------" << std::endl;

    int zeroValue{}; // this will initialize 0

    // int narrowValue {3.9}; // this will give a compiletime error that we can't initialize a decimal value to a integer

    int value1(3.6);  // This is C++ "functional-style" initialization (looks like calling a constructor).
    int value2 = 3.6; // This is copy initialization using this (=) sign.

    // the value1 and value2 initialization doesn't have any diff. except the style, one is using the function style and another one is using the assignment operator

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(value1) << std::endl;
    std::cout << value1 << "-" << value2 << std::endl;

    int num1{-69};
    signed int num2{-1000};
    // unsigned int num3 {-1000}; // this will also gives a compile time error

    std::cout << num1 << std::endl
              << num2 << std::endl;
    std::cout << sizeof(num2) << std::endl;

    std::cout << "--------------float----------------" << std::endl;

    float x{123.456789123f};
    std::cout << x << std::endl;
    std::cout << std::setprecision(0) << x << std::endl;
    std::cout << std::setprecision(5) << x << std::endl;
    std::cout << std::setprecision(10) << x << std::endl;
    std::cout << std::fixed << std::setprecision(10) << x << std::endl;
    std::cout << std::endl; // after decimal 10 fixed values will be printed

    std::cout.unsetf(std::ios::fixed);
    float x2 = 32222228987890;
    std::cout << x2 << std::endl;
    std::cout << std::setprecision(0) << x2 << std::endl;
    std::cout << std::setprecision(5) << x2 << std::endl;
    std::cout << std::setprecision(10) << x2 << std::endl;
    std::cout << std::fixed << std::setprecision(10) << x2 << std::endl;

    std::cout << "--------------double----------------" << std::endl;

    std::cout.unsetf(std::ios::fixed);
    double y{1.924e8};
    double y2{1924000000};
    double y3{19240000000};
    double y4{3.9248957908375e-8};
    double y5{0.00003924};
    double y6{0.0003924};

    std::cout << y << std::endl;
    std::cout << y2 << std::endl;
    std::cout << y3 << std::endl;
    std::cout << y4 << std::endl;
    std::cout << y5 << std::endl;
    std::cout << y6 << std::endl;

    std::cout << std::endl;

    std::cout << std::setprecision(10) << y << std::endl;
    std::cout << std::setprecision(40) << y2 << std::endl;
    std::cout << std::setprecision(30) << y3 << std::endl;
    std::cout << std::setprecision(30) << y4 << std::endl;
    std::cout << std::setprecision(30) << y5 << std::endl;
    std::cout << std::setprecision(30) << y6 << std::endl;

    std::cout << std::endl;
    std::cout << std::fixed;

    std::cout << std::setprecision(10) << y << std::endl;
    std::cout << std::setprecision(40) << y2 << std::endl;
    std::cout << std::setprecision(30) << y3 << std::endl;
    std::cout << std::setprecision(30) << y4 << std::endl;
    std::cout << std::setprecision(30) << y5 << std::endl;
    std::cout << std::setprecision(30) << y6 << std::endl;

    std::cout.unsetf(std::ios::fixed);

    std::cout << "--------------Zero----------------" << std::endl;

    double n1{5.6};
    double n2{};
    double n3{};

    std::cout << n1 / n2 << std::endl; // this will give output = infinite
    std::cout << n2 / n3 << std::endl; // this will give output = nan (not a number)
    std::cout << n2 / n1 << std::endl;

    if (std::isinf(n1 / n2))
    {
        std::cout << "Infinity detected!" << std::endl;
    }
    if (std::isnan(n2 / n3))
    {
        std::cout << "NaN detected!" << std::endl;
    }

    std::cout << "--------------booleans----------------" << std::endl;

    bool t{true};
    bool t1{0};
    bool t2{1};
    bool t3{false};

    if (t2)
    {
        std::cout << "Hello" << std::endl;
    }
    else
    {
        std::cout << "Hi" << std::endl;
    }

    std::cout << "--------------chars----------------" << std::endl;

    char c1{65};
    char c2{'A'};

    std::cout << c1 << std::endl;
    std::cout << static_cast<int>(c2) << std::endl;

    std::cout << "--------------auto----------------" << std::endl;

    auto v1{20};
    auto v2{2.90f};
    auto v3{2.890l};
    auto v4{'e'};
    v4 = 'a';

    auto v5{334u};
    v5 = -889;

    std::cout << sizeof(v1) << std::endl;
    std::cout << sizeof(v2) << std::endl;
    std::cout << sizeof(v3) << std::endl;
    std::cout << sizeof(v4) << std::endl;
    std::cout << v4 << std::endl;
    std::cout << v5 << std::endl;



    return 0;
}