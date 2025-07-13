#include <iostream>
#include <concepts>

// Syntax style 1
template <typename T>
    requires std::integral<T>
T add(T a, T b)
{
    return a + b;
}

// // Syntax style 2
// template <std::integral T>
// T add(T a, T b)
// {
//     return a + b;
// }

// // Syntax style 3
// auto add(std::integral auto a, std::integral auto b)
// {
//     return a + b;
// }

// // Syntax style 4
// template <typename T>
// T add(T a, T b)
//     requires std::integral<T>
// {
//     return a + b;
// }

// The syntax above are all same just use onyl one 


auto add(auto a, auto b)
{
    return a + b;
}

int main()
{

    char a{10};
    char a2{20};

    auto result_a = add(a, a2);
    std::cout << "result_a : " << static_cast<int>(result_a) << std::endl;

    int b{11};
    int b2{5};
    auto result_b = add(b, b2);
    std::cout << "result_b : " << result_b << std::endl;

    double c{11.1};
    double c2{1.5};
    auto result_c = add(c, c2);
    std::cout << "result_c : " << result_c << std::endl;

    return 0;
}