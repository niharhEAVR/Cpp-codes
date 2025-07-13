#include <iostream>
#include <cstring>

template <typename T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

// template <>
// const char *maximum<const char *>(const char *a, const char *b)
// {
//     return (std::strcmp(a, b) > 0) ? a : b;
// }

int main()
{

    int a{10}, b{23};
    double c{34.7}, d{23.4};
    std::string e{"hello"}, f{"world"};

    auto max_int = maximum(a, b);    // int type deduced
    auto max_double = maximum(c, d); // double type deduced
    auto max_str = maximum(e, f);    // string type deduced

    std::cout << "max_int : " << max_int << std::endl;
    std::cout << "max_double : " << max_double << std::endl;
    std::cout << "max_str : " << max_str << std::endl;

    const char *g{"wild"}, *h{"animal"};

    const char *result = maximum(g, h);
    std::cout << "max(const char*) : " << result << std::endl;

    return 0;
}
