#include<iostream>

int main()
{
    int age;
    std::string fullName;

    std::cout << "Enter your full name: ";
    std::getline(std::cin,fullName) >> age;

    std::cout << "Your name is: " << fullName << " Your age is: " << age << std::endl;

    return 0;
}