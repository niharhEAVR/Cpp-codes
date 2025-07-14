#include <iostream>
#include <concepts>

template <typename T>
concept TinyType = requires {
    requires sizeof(T) <= 4;
};

template <typename T>
concept Mulable = requires(T a, T b) {
    { a * b } -> std::convertible_to<int>;
};

template <typename T>
    requires TinyType<T>
T add(T a)
{
    std::cout << "TinyType add() called\n";
    return a;
}

template <typename T>
    requires Mulable<T>
T add(T a, T b)
{
    std::cout << "Mulable add() called\n";
    return a * b;
}

int main()
{
    double x{6.7};
    double y{5.6};

    char a{'a'};
    char b{'b'};

    auto result = add(x, y);
    auto result2 = add(a);

    std::cout << "result : " << result << std::endl;
    std::cout << "sizeof(result) : " << sizeof(result) << std::endl;

    std::cout << "result2 : " << result2 << std::endl;
    std::cout << "sizeof(result2) : " << sizeof(result2) << std::endl;

    return 0;
}
