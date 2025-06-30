#include <iostream>
#include <cstring>

int main()
{

    const char message1[]{"The sky is blue."};

    // std::strlen : Find the length of a string
    // strlen ignores null character
    std::cout << "strlen(message1) : " << std::strlen(message1) << std::endl;

    // sizeof Includes the null character
    std::cout << "sizeof(message1) : " << sizeof(message1) << std::endl;

    // Array decays into pointer when we use const char*
    const char *message2{"The sky is blue."};

    // strlen still works with decayed arrays
    std::cout << "strlen(message2) : " << std::strlen(message2) << std::endl;

    // Prints size of pointer not the string size
    std::cout << "sizeof(message2) : " << sizeof(message2) << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    // std::strcmp - signature : int strcmp( const char *lhs, const char *rhs );
    // Returns negative value if lhs appears before rhs in lexicographical order,
    // Zero if lhs and rhs compare equal.
    // and Positive value if lhs appears after rhs in lexicographical order.
    const char *string_data1{"Alabama"};
    const char *string_data2{"Blabama"};
    char string_data3[]{"Alabama"};
    char string_data4[]{"Blabama"};

    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << std::endl;

    std::cout << "std::strcmp (" << string_data3 << "," << string_data4 << ") : "
              << std::strcmp(string_data3, string_data4) << std::endl;

    string_data1 = "Alabama";
    string_data2 = "Alabamb";
    // string_data3 = "Alabama";
    // string_data4 = "Alabamb";

    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "Alacama";
    string_data2 = "Alabama";

    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "India";
    string_data2 = "France";

    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << std::endl;

    string_data1 = "Kigali";
    string_data2 = "Kigali";

    std::cout << "std::strcmp (" << string_data1 << "," << string_data2 << ") : "
              << std::strcmp(string_data1, string_data2) << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    // std::strncmp : int strncmp( const char *lhs, const char *rhs, std::size_t count );
    // Compares n characters in the strings
    // Returns : Negative value if lhs appears before rhs in lexicographical order.
    // Zero if lhs and rhs compare equal, or if count is zero.
    // Positive value if lhs appears after rhs in lexicographical order.

    string_data1 = "Alabama";
    string_data2 = "Blabama";
    size_t n{3};
    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : "
              << std::strncmp(string_data1, string_data2, n) << std::endl;

    string_data1 = "aaaia";
    string_data2 = "aaance";

    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : "
              << std::strncmp(string_data1, string_data2, n) << std::endl;

    n = 5;

    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : "
              << std::strncmp(string_data1, string_data2, n) << std::endl;

    string_data1 = "aaaoa";
    string_data2 = "aaance";

    std::cout << "std::strncmp (" << string_data1 << "," << string_data2 << "," << n << ") : "
              << std::strncmp(string_data1, string_data2, n) << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    // Find the first occurrence of a character
    // CODE STOLEN FROM THE DOCS :
    // doc : https://en.cppreference.com/w/cpp/string/byte/strchr
    // we use std::strchr to find all the characters one by one.

    const char *const str{"Try not. Do, or do not. There is no try."};
    // Can make this a const pointer to prevent users from making it point somewhere else
    char target = 'T';
    const char *result = str;
    size_t iterations{};

    while ((result = std::strchr(result, target)) != nullptr)
    {
        std::cout << "Found '" << target << "' starting at '" << result << "'\n";
        ++result;
        std::cout << result << std::endl;
        ++iterations;
    }
    std::cout << "iterations : " << iterations << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    {
        // A bad version that will loop 25 times
        const char *str{"Try not. Do, or do not. There is no try."};
        char target = 'T';
        const char *result{nullptr};
        size_t iterations{};

        while ((result = std::strchr(str, target)) != nullptr)
        {
            std::cout << "Found " << target << " - ";

            // Increment result, otherwise we'll find target at the same location
            ++str; // Making the pointer point to the next character
            std::cout << str << std::endl;
            ++iterations;
        }
        std::cout << "iterations : " << iterations << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    std::cout << std::endl;

    // Find last occurence
    // CODE STOLEN FROM THE DOCS :
    // doc : https://en.cppreference.com/w/cpp/string/byte/strrchr

    char input[] = "/home/user/hello.cpp";
    char *output = std::strrchr(input, '/');
    if (output)
        std::cout << output+1 << std::endl;
    //+1 because we want to start printing past
    // the character found by std::strrchr.
    return 0;
}