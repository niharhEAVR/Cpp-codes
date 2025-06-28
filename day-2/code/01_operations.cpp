#include <iostream>

int main()
{
    std::cout << "-----------------Operators------------------" << std::endl;

    int number1{2};
    int number2{7};

    int result = number1 + number2;
    std::cout << "result1 : " << result << std::endl;

    result = number2 - number1;
    std::cout << "result2 : " << result << std::endl;

    result = number1 - number2;
    std::cout << "result3 : " << result << std::endl;

    result = number1 * number2;
    std::cout << "result4 : " << result << std::endl;

    result = number2 / number1;
    std::cout << "result5 : " << result << std::endl;

    result = number2 % number1;
    std::cout << "result6 : " << result << std::endl;

    result = 31 % 10;
    std::cout << "result7 : " << result << std::endl;

    std::cout << "-----------------Precedence & Associativity------------------" << std::endl;

    int a{6};
    int b{3};
    int c{8};
    int d{9};
    int e{3};
    int f{2};
    int g{5};

    result = a + b * c - d / e - f + g;

    std::cout << "result8 : " << result << std::endl;

    result = a / b * c + d - e + f; //   16 + 9 - 3 + 2
    std::cout << "result9 : " << result << std::endl;

    result = (a + b) * c - d / e - f + g; // 72-3-2+5
    std::cout << "result () : " << result << std::endl;

    std::cout << "-----------------Prefix & Postfix------------------" << std::endl;

    int value{5};

    std::cout << "The value is (incrementing) : " << value++ << std::endl;
    std::cout << "The value is : " << value << std::endl;

    std::cout << "The value is (decrementing) : " << value-- << std::endl;
    std::cout << "The value is : " << value << std::endl;

    std::cout << "The value is (prefix++) : " << ++value << std::endl;

    std::cout << "The value is (prefix--) : " << --value << std::endl;

    std::cout << "-----------------Assignment Operators------------------" << std::endl;

    value = 5;
    value += 5;
    value -= 5;
    value *= 2;
    value /= 3;
    value %= 11;
    std::cout << "The value is (after %=11) : " << value << std::endl;

    std::cout << "-----------------Relational Operators------------------" << std::endl;

    number1 = 20;
    number2 = 20;

    std::cout << std::boolalpha; // Make bool show up as true/false instead of 1/0

    std::cout << "number1 < number2 : " << (number1 < number2) << std::endl;
    std::cout << "number1 <= number2 : " << (number1 <= number2) << std::endl;
    std::cout << "number1 > number2 : " << (number1 > number2) << std::endl;
    std::cout << "number1 >= number2 : " << (number1 >= number2) << std::endl;
    std::cout << "number1 == number2 : " << (number1 == number2) << std::endl;
    std::cout << "number1 != number2 : " << (number1 != number2) << std::endl;

    std::cout << std::endl;
    std::cout << "store comparison result and use it later" << std::endl;

    bool flag = (number1 == number2);
    std::cout << number1 << " == " << number2 << " : " << flag << std::endl;

    std::cout << "-----------------Logical Operators------------------" << std::endl;

    bool x{true};
    bool y{false};
    bool z{true};

    std::cout << std::boolalpha; // true / false

    std::cout << "Basic AND operations" << std::endl;

    std::cout << " x && y : " << (x && y) << std::endl;          
    std::cout << " x && z : " << (x && z) << std::endl;          
    std::cout << " x && y && z :" << (x && y && z) << std::endl; 

    std::cout << "Basic OR operations" << std::endl;
    std::cout << " x || y : " << (x || y) << std::endl;          
    std::cout << " x || z : " << (x || z) << std::endl;          
    std::cout << " x || y || z :" << (x || y || z) << std::endl; 

    std::cout << "Basic NOT operations" << std::endl;

    std::cout << "!x : " << !x << std::endl;
    std::cout << "!y : " << !y << std::endl;
    std::cout << "!z : " << !z << std::endl;

    std::cout << "Combining logical operators" << std::endl;
    std::cout << "!(x && y) || z : " << (!(x && y) || z) << std::endl; // true

    int s{45};
    int o{20};
    int t{11};

    std::cout << "Relational and logic operations on integers" << std::endl;

    std::cout << "(s > o) && (s > t) : " << ((s > o) && (s > t)) << std::endl; // true
    std::cout << "(s==o) || (o <= t ) : " << ((s == o) || (o <= t)) << std::endl;
    std::cout << "(s < o) || (s > t) : " << ((s < o) || (s > t)) << std::endl;
    std::cout << "(t > o) || (s < t) : " << ((t > o) || (s < t)) << std::endl;
    std::cout << "(s > t) && (t <= s) : " << ((s > t) && (t <= s)) << std::endl;
    std::cout << "(s > o) && (s <= t) : " << ((s > o) && (s <= t)) << std::endl;
    std::cout << "(! a) && (s == o) : " << ((!a) && (s == o)) << std::endl;
    std::cout << "(! a) && (s == o) : " << ((!a) && (s == o)) << std::endl;

    return 0;
}