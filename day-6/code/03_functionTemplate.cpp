#include <iostream>
#include <string>

template <typename T> T max(T a, T b);

int main()
{

    int x{5};
    int y{7};

    int *p_x{&x};
    int *p_y{&y};

    auto result = max(p_x, p_y);
    std::cout << "result : " << *result << std::endl;

    std::string str1 = "Apple";
    std::string str2 = "Pie";

    std::string result2 = ::max(str1, str2);
    std::cout << "Max string: " << result2 << std::endl;


    return 0;
}

template <typename T>
T max(T a, T b)
{
    std::cout << "Type: " << typeid(T).name() << "\n";
    return (a > b) ? a : b;
}