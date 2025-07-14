#include <iostream>
#include <type_traits>
#include <concepts>

template <typename T>
concept MyIntegral = std::is_integral_v<T>;

MyIntegral auto add(MyIntegral auto a, MyIntegral auto b)
{
    std::cout<< "MyIntegral auto add uses" <<std::endl;
    return a + b;
}

template <typename T>
concept Multipliable = requires(T a, T b) {
    a * b;
};

template <typename T>
concept Incrementable = requires(T a) {
    a += 1;
    ++a;
    a++;
};

template <typename T>
requires Incrementable<T>
T add(T a, T b)
{
    std::cout<< "template <typename T> requires Incrementable<T> uses" <<std::endl;
    return a + b;
}

int main()
{

    double x{6};
    double y{7};

    int a{2};
    int b{};

    double name = add(x, y);
    int name2 = add(a, b);
    std::cout<<name<<std::endl;
    std::cout<<name2<<std::endl;

    return 0;
}