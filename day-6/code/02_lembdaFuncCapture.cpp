#include <iostream>

int main()
{

    // Capture clause
    double a{10};
    double b{20};

    auto func = [a, b]()
    {
        std::cout << "a + b : " << a + b << std::endl;
    };
    func();

    std::cout << "----------------------\n"
              << std::endl;

    // Capturing by value
    int c{42};

    auto func2 = [c]()
    {
        std::cout << "Inner value : " << c << " &inner : " << &c << std::endl;
    };

    for (size_t i{}; i < 5; ++i)
    {
        std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
        func2();
        ++c;
    }

    std::cout << "----------------------\n"
              << std::endl;

    // Capture by reference
    int d{42};

    auto func3 = [&d]()
    {
        std::cout << "Inner value : " << d << " &inner : " << &d << std::endl;
    };

    for (size_t i{}; i < 5; ++i)
    {
        std::cout << "Outer value : " << d << " &outer : " << &d << std::endl;
        func3();
        ++d;
    }

    std::cout << "----------------------\n"
              << std::endl;

    auto func4 = [=]()
    {
        std::cout << "Inner value of a: " << a << " &a : " << &a << std::endl;
        std::cout << "Inner value of b: " << b << " &b : " << &b << std::endl;
        std::cout << "Inner value of c: " << c << " &c : " << &c << std::endl;
        std::cout << "Inner value of d: " << d << " &d : " << &d << std::endl;
    };

    for (size_t i{}; i < 2; ++i)
    {
        std::cout << "Outer value of a: " << a << " &a : " << &a << std::endl;
        std::cout << "Outer value of b: " << b << " &b : " << &b << std::endl;
        std::cout << "Outer value of c: " << c << " &c : " << &c << std::endl;
        std::cout << "Outer value of d: " << d << " &d : " << &d << std::endl;
        std::cout << std::endl;
        func4();
        std::cout << std::endl;
        a++;
        b++;
        c++;
        d++;
    }

    return 0;
}