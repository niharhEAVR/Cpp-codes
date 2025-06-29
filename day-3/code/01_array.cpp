#include <iostream>

int main()
{

    int scores[5];
    // garbase values for uninitialized array and outbound arrays
    for (size_t i{0}; i < 7; ++i)
    {
        if (i == 6)
        {
            std::cout << "[" << i << "]=" << scores[i];
            break;
        }
        std::cout << "[" << i << "]=" << scores[i] << ", ";
    }
    std::cout << std::endl
              << std::endl;

    scores[0] = 20;
    scores[1] = 21;
    scores[2] = 22;
    for (size_t i{0}; i < 5; ++i)
    {
        if (i == 4)
        {
            std::cout << "score[" << i << "]=" << scores[i];
            break;
        }
        std::cout << "score[" << i << "]=" << scores[i] << ", ";
    }
    std::cout << std::endl
              << std::endl;

    double salaries[5]{12.7, 7.5, 13.2, 8.1, 9.3};
    for (size_t i{0}; i < 5; ++i)
    {
        std::cout << "salaries[" << i << "]=" << salaries[i] << ", ";
    }
    std::cout << std::endl
              << std::endl;

    // If you don't initialize all the elements, those you leave out are initialized to 0
    int families[5]{12, 7, 5};
    for (size_t i{0}; i < 5; ++i)
    {
        std::cout << "families[" << i << "]=" << families[i] << ", ";
    }
    std::cout << std::endl
              << std::endl;

    // Omit the size of the array at declaration
    int class_sizes[]{5, 12, 15, 11, 18, 17, 23, 56};
    // Will print this with a range based for loop
    for (auto value : class_sizes)
    {
        std::cout << "value : " << value << ", ";
    }
    std::cout << std::endl
              << std::endl;

    std::cout << "-------------size-of-arrays-------------" << std::endl;
    std::cout << sizeof(scores) << std::endl;
    std::cout << sizeof(scores[4]) << std::endl;
    std::cout << "items count of score: " << sizeof(scores) / sizeof(scores[4]) << std::endl;
    std::cout << sizeof(salaries) << std::endl;
    std::cout << sizeof(salaries[4]) << std::endl;
    std::cout << "items count of score: " << sizeof(salaries) / sizeof(salaries[4]) << std::endl;
    std::cout << sizeof(families) << std::endl;
    std::cout << sizeof(families[4]) << std::endl;
    std::cout << "items count of score: " << sizeof(families) / sizeof(families[4]) << std::endl;

    std::cout << "-------------array-of-characters-------------" << std::endl;

    // If a character array is null terminated, it's called as C-String
    char message1[]{'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << "message1 : " << message1 << std::endl;
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

    // This  array is null terminated but its invisible
    char message2[6]{'H', 'e', 'l', 'l', 'o'};
    std::cout << "message2 : " << message2 << std::endl;
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;

    // This is not a c string , as there is not null character
    char message3[]{'H', 'e', 'l', 'l', 'o'};
    std::cout << "message3 : " << message3 << std::endl;
    std::cout << "sizeof(message3) : " << sizeof(message3) << std::endl;

    // String literal
    char message4[]{"Hello"};
    std::cout << "message4 : " << message4 << std::endl;
    std::cout << "sizeof(message4) : " << sizeof(message4) << std::endl;

    // char message5[5]{"Hello"}; // this will give error because the size is 5 and its null character doesnt have space to initialize
    return 0;
}