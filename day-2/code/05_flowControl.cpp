#include <iostream>

const int Pen{10};
const int Marker{20};

int main()
{

    int number1{75};
    int number2{760};
    int number3{550};

    // if-else-if
    if (number1 > number2)
    {
        if (number1 > number3)
        {
            std::cout << number1 << std::endl;
        }
        else
        {
            std::cout << number3 << std::endl;
        }
    }
    else
    {
        if (number2 > number3)
        {
            std::cout << number2 << std::endl;
        }
        else
        {
            std::cout << number3 << std::endl;
        }
    }

    // switch case
    int tool{Marker};
    if (tool == Pen)
    {
        std::cout << "Active tool is pen" << std::endl;
    }
    else if (tool == Marker)
    {
        std::cout << "Active tool is Marker" << std::endl;
    }
    else
    {
        std::cout << "Choose a Tool!!" << std::endl;
    }

    tool = Marker;
    // Switch condition can only be integer of enum, and char
    switch (tool)
    {
    case Pen:
    {
        std::cout << "Active tool is Pen" << std::endl;
    }
    break;
    case Marker:
    {
        std::cout << "Active tool is Marker" << std::endl;
    }
    break;
    default:
    {
        std::cout << "No match found" << std::endl;
    }
    break;
    }

    // ternary operator
    int max = (number2 < number1) ? number1 : number2;
    // if     a    <    b  = true then store a -> on max
    // if     a    <    b  = false then store b -> on max
    std::cout << max << std::endl;

    // loops
    int count{0};
    for (unsigned int i{0}; i < 10; i++)
    {
        count += i;
    }
    std::cout << "The value of count: " << count << std::endl;

    // Use size_t : a representation of some unsigned int for positive numbers [sizes]
    /*
    for(size_t i{0} ; i < 10 ; ++i){
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    */
    /*
    //sizeof(size_t)
    std::cout << "sizeof(size_t) : " << sizeof(size_t) << std::endl;
    */

    // Scope of the iterator
    /*
    for(size_t i{0} ; i < 10 ; ++i){
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    // std::cout << "i : " << i << std::endl;Compiler error : i is not in scope
    */

    size_t i{0}; // Iterator defined outside
    for (; i < 10; ++i)
    {
        std::cout << i << " : I love C++" << std::endl;
    }
    std::cout << "Loop done!" << std::endl;
    std::cout << "i : " << i << std::endl;

    return 0;
}