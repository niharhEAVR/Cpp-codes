#include <iostream>

int main()
{
    /*

    // Case1 : Uninitialized pointer
    int * p_number; // Dangling uninitialized pointer
    std::cout << "p_number : " << p_number << std::endl;
    std::cout << "*p_number : " << *p_number << std::endl; //CRASH!

    // Case 2 : deleted pointer
    int * p_number1 {new int{67}};
    std::cout << "*p_number1 (before delete) : " << *p_number1 << std::endl;
    delete p_number1;
    std::cout << "*p_number1(after delete) : " << *p_number1 << std::endl;

    // Case 3 : Multiple pointers pointing to same address
    int *p_number3 {new int{83}};
    int *p_number4 {p_number3};
    std::cout << "p_number3 - " << p_number3 << " - " << *p_number3 << std::endl;
    std::cout << "p_number4 - " << p_number4 << " - " << *p_number4 << std::endl;
    delete p_number3;
    //p_number4 points to deleted memory. Dereferncing it will lead to
    //undefined behaviour : Crash/ garbage or whatever
    std::cout<< "p_number4(after deleting p_number3) - " << p_number4 << " - " << *p_number4 << std::endl;

    */

    // Solution1 : Initialize your pointers immediately upon declaration
    int *p_number5{nullptr};
    int *p_number6{new int(87)};
    if (p_number6 != nullptr)
    {
        std::cout << "*p_number6 : " << *p_number6 << std::endl;
    }
    else
    {
        std::cout << "Invalid address" << std::endl;
    }

    // Solution 2 :
    // Right after you call delete on a pointer, remember to reset
    // the pointer to nullptr to make it CLEAR it doesn't point anywere
    int *p_number7{new int{82}};
    std::cout << "p_number7 - " << p_number7 << " - " << *p_number7 << std::endl;
    delete p_number7;
    p_number7 = nullptr; // Reset the pointer
    // Check for nullptr before use
    if (p_number7 != nullptr)
    {
        std::cout << "*p_number7 : " << *p_number7 << std::endl;
    }
    else
    {
        std::cout << "Invalid memory access!" << std::endl;
    }

    // Solution 3
    // For multiple pointers pointing to the same address ,  Make sure there is
    // one clear pointer (master pointer) that owns the memory ( responsible for releasing when necessary)
    // other pointers should only be able to dereference when the master pointer is valid
    std::cout << "Solution 3 : " << std::endl;
    int *p_number8{new int{382}}; // Let's say p_number8 is the master pointer
    int *p_number9{p_number8};

    std::cout << "p_number8 - " << p_number8 << " - " << *p_number8 << std::endl;

    if (!(p_number8 == nullptr))
    { // Only use slave pointers when master pointer is valid
        std::cout << "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
    }

    delete p_number8; // Master releases the memory
    p_number8 = nullptr;

    if (!(p_number8 == nullptr))
    { // Only use slave pointers when master pointer is valid
        std::cout << "p_number9 - " << p_number9 << " - " << *p_number9 << std::endl;
    }
    else
    {
        std::cerr << "WARNING : Trying to use an invalid pointer" << std::endl;
    }

    
    return 0;
}