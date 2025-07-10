#include <iostream>

int main()
{

    // Check if character is alphanumeric
    std::cout << "C is alphanumeric: " << std::isalnum('C') << std::endl;
    std::cout << "^ is alphanumeric: " << std::isalnum('^') << std::endl;

    // Can use this as a test condition
    char input_char{'*'};
    if (std::isalnum(input_char))
        std::cout << input_char << " is alhpanumeric." << std::endl;
    else
        std::cout << input_char << " is not alphanumeric." << std::endl;

    // Check if character is alphabetic
    std::cout << std::endl;
    std::cout << "e is alphabetic: " << std::isalpha('e') << std::endl;
    std::cout << "^ is alphabetic: " << std::isalpha('^') << std::endl;
    std::cout << "7 is alphabetic: " << std::isalpha('7') << std::endl;

    if (std::isalpha('e'))
        std::cout << 'e' << " is alphabetic" << std::endl;
    else
        std::cout << 'e' << " is NOT alphabetic" << std::endl;

    // Check if a character is blank
    std::cout << std::endl;
    char message[]{"Hello there. How are you doing? The sun is shining."};

    // Find and print blank index
    size_t blank_count{};
    for (size_t i{0}; i < std::size(message); ++i)
    {
        if (std::isblank(message[i]))
        {
            ++blank_count;
        }
    }
    std::cout << "In total we found '" << blank_count << "' blank characters." << std::endl;

    // Check if character is lowercase or uppercase
    char thought[]{"The C++ Programming Language is one of the most used on the Planet"};
    size_t lowercase_count{};
    size_t upppercase_count{};

    for (auto character : thought)
    {
        if (std::islower(character))
        {
            ++lowercase_count;
        }
        if (std::isupper(character))
        {
            ++upppercase_count;
        }
    }
    std::cout << std::endl;
    std::cout << "Found '" << lowercase_count << "' lowercase characters and '" << upppercase_count << "' uppercase characters." << std::endl;

    // Check if a character is a digit
    std::cout << std::endl;
    char statement[]{"Mr Hamilton owns 221 cows. That's a lot of cows! The kid exclamed."};
    size_t digit_count{};
    for (auto character : statement)
    {
        if (std::isdigit(character))
        {
            ++digit_count;
        }
    }
    std::cout << "Found '" << digit_count << "' digits in the statement string" << std::endl;

    // Turning a character to lowercase using the std::tolower() function
    std::cout << std::endl;
    char original_str[]{"Home. The feeling of belonging"};
    char dest_str[std::size(original_str)];

    // Turn this to uppercase. Change the array in place
    for (size_t i{}; i < std::size(original_str); ++i)
    {
        dest_str[i] = std::toupper(original_str[i]);
    }

    std::cout << "Original string: " << original_str << std::endl;
    std::cout << "Uppercase string: " << dest_str << std::endl;

    // Turn this to lowercase. Change the array in place
    for (size_t i{}; i < std::size(original_str); ++i)
    {
        dest_str[i] = std::tolower(original_str[i]);
    }
    std::cout << "Lowercase string " << dest_str << std::endl;

    return 0;
}