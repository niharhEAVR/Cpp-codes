#include <iostream>

int main(){

    char * message {"Hello World!"};
    std::cout << "message : " << message << std::endl;
    std::cout << "size of the message pointer : " << sizeof(message) << std::endl;

    // *message = "B"; // Compiler error, read the 04_charPointer.md to understand properly
    std::cout << "*message : " << *message << std::endl;

    //Allow users to modify the string (only possible by array)
    char message1[] {"Hello World!"};
    message1[0] = 'B';
    std::cout << "message1 : " << message1 << std::endl;
    
    return 0;
}