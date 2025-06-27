#include<iostream>

int main()
{
    int decimalNum = 15;
    int octalNum = 014;
    int hexaNum = 0x0f;
    int binaryNum = 0b0000111;


    std::cout << "Ocatl number is: " << octalNum << std::endl;
    std::cout << "Hexadecimal number is: " << hexaNum << std::endl;
    std::cout << "Binary number is: " << binaryNum << std::endl;

    return 0;
}