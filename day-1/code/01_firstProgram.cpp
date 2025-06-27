#include<iostream>

int main()
{
    int x; 
    int y {2}; 
    std::cout << "Enter a number: ";    
    std::cin >> x;
    std::cout << "The double of that number is: " << x*y << std::endl;
    return 0;
}