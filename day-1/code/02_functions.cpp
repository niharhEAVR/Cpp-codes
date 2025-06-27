#include<iostream>

int addNumbers(int a, int b);

int main()
{
    std::cout << "result: " << addNumbers(3,4) << std::endl;   
    return 0;
}

int addNumbers(int a, int b){
    return a+b;
}