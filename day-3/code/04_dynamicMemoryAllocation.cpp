#include <iostream>

int main()
{

    // Dynamic heap memory
    int *p_number{nullptr};
    p_number = new int;
    // Dynamically allocate space for a single int on the heap
    // This memory belongs to our program from now on.
    // The system can't use it for anything else, untill we return it.
    // After this line executes, we will have a valid memory location allocated.
    // The size of the allocated memory will be such that it
    // can store the type pointed to by the pointer

    *p_number = 77; // Writting into dynamically allocated memory
    std::cout << "*p_number : " << *p_number << std::endl;
    // Return memory to the OS
    delete p_number;
    p_number = nullptr;

    // It is also possible to initialize the pointer with a valid
    // address up on declaration. Not with a nullptr
    int *p_number2{new int};     // Memory location contains junk value
    int *p_number3{new int(22)}; // use direct initialization
    int *p_number4{new int{23}}; // use uniform initialization

    std::cout << std::endl;
    std::cout << "Initialize with valid memory address at declaration : " << std::endl;
    std::cout << "p_number2 : " << p_number2 << std::endl;
    std::cout << "*p_number2 : " << *p_number2 << std::endl; // Junk value

    std::cout << "p_number3 : " << p_number3 << std::endl;
    std::cout << "*p_number3 : " << *p_number3 << std::endl;

    std::cout << "p_number4 : " << p_number4 << std::endl;
    std::cout << "*p_number4 : " << *p_number4 << std::endl;

    // Remember to release the memory
    delete p_number2;
    p_number2 = nullptr;

    delete[] p_number3;
    p_number3 = nullptr;

    delete[] p_number4;
    p_number4 = nullptr;

    // Can reuse pointers
    p_number2 = new int(81);
    std::cout << "*p_number : " << *p_number2 << std::endl;

    delete[] p_number2;
    p_number2 = nullptr;

    // Calling delete twice on a pointer : BAD!
    p_number2 = new int(99);
    std::cout << "*p_number2 : " << *p_number2 << std::endl;
    delete[] p_number2;
    // delete[] p_number2;

    return 0;
}