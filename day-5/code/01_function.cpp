#include <iostream>
#include <random>

int max(int a, int b);
// Function declaration , prototype
// Signature doesn't include return type

double maxDouble(double a, double b);

int main()
{

    std::random_device rd;                                  // non-deterministic seed
    std::mt19937 gen(rd());                                 // Mersenne Twister generator
    std::uniform_int_distribution<> distInt(1, 100);        // range: [1, 100]
    std::uniform_real_distribution<> distDouble(1.0, 10.0); // range: [1.0, 10.0]

    int x{distInt(gen)};
    int y{distInt(gen)};

    int result = max(x, y);
    std::cout << "max : " << result << std::endl;

    double a{distDouble(gen)};
    double b{distDouble(gen)};

    double resultDouble = maxDouble(a, b);
    std::cout << "maxDouble : " << resultDouble << std::endl;

    return 0;
}

// Function definition. Shows up after main
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

double maxDouble(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}