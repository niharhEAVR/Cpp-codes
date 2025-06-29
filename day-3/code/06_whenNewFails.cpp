#include <iostream>
#include <new> // For std::nothrow

int main()
{
    // Exception-based allocation
    int* data1 = nullptr;

    try
    {
        data1 = new int[1000000000000000000]; // May throw std::bad_alloc
        std::cout << "data1 allocated successfully with exceptions.\n";
    }
    catch (std::exception &ex)
    {
        std::cout << "Something went wrong (exception): " << ex.what() << std::endl;
    }

    // Always check before deleting
    if (data1 != nullptr)
    {
        delete[] data1;
        std::cout<< "data1 deleted" << std::endl;
        data1 = nullptr;
    }else{
        std::cout<< "data1 not allocated so not need to delete" << std::endl;
    }
    std::cout << std::endl;

    
    // nothrow allocation
    int* data2 = new (std::nothrow) int[1000000000000000000];
    if (data2 != nullptr)
    {
        std::cout << "data2 allocated successfully using nothrow.\n";
        delete[] data2;
        data2 = nullptr;
    }
    else
    {
        std::cout << "data2 allocation failed (nothrow).\n";
    }

    return 0;
}
