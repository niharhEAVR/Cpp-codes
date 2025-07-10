#include <iostream>

int main()
{

    int int_data{33};
    double double_data{55};

    // References
    int &ref_int_data{int_data};
    double &ref_double_data{double_data};

    // Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << std::endl;
    
    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
    
    std::cout << "=======================" << std::endl;

    int_data = 111;
    double_data = 67.2;

    // Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << std::endl;
    
    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
    
    std::cout << "=======================" << std::endl;

    ref_int_data = 1012;
    ref_double_data = 1000.45;

    // Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << std::endl;
    
    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
    
    std::cout << "=======================" << std::endl;

    // Declare pointer and reference
    double double_value{12.34};
    double &ref_double_value{double_value}; // Reference to double_value
    double *p_double_value{&double_value};  // Pointer to double_value
    
    // Reading
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;

    // Writting through pointer
    *p_double_value = 15.44;

    std::cout << std::endl;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    
    // Writting through reference
    std::cout << "=======================" << std::endl;

    ref_double_value = 18.44;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    
    std::cout << "=======================" << std::endl;
    
    
    double some_other_double{78.45};
    // Make the reference reference something else.
    ref_double_value = some_other_double;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    
    // Make the pointer point to something else
    std::cout << "=======================" << std::endl;

    p_double_value = &some_other_double;
    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    
    std::cout << "=======================" << std::endl;

    *p_double_value = 555.5;

    std::cout << "double_value : " << double_value << std::endl;
    std::cout << "ref_double_value : " << ref_double_value << std::endl;
    std::cout << "&double_value : " << &double_value << std::endl;
    std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
    std::cout << "p_double_value : " << p_double_value << std::endl;
    std::cout << "*p_double_value : " << *p_double_value << std::endl;
    
    std::cout << "=======================" << std::endl;

    
    
    int scores[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Scores : ";
    for (auto score : scores)
    {
        std::cout << " " << score;
    }
    std::cout << std::endl;

    for (auto &score : scores)
    {
        score = score * 10;
    }

    // Printing after change
    std::cout << std::endl;
    std::cout << "Scores : ";
    for (auto score : scores)
    {
        std::cout << " " << score;
    }
    std::cout << std::endl;

    return 0;
}