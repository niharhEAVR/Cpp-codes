#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
class CivilEngineer : public Engineer
{
    friend std::ostream &operator<<(std::ostream &, const CivilEngineer &operand);

public:
    void build_road()
    {
        // get_full_name(); // Compiler error
        /// m_full_name = "Daniel Gray"; //Compiler error
        // m_age = 45; // Compiler error

        add(10, 2);
        add(10, 2, 4);
        get_address(); // it will give error on the compiling time , because you are not using keyword
        get_full_name(); // this is okay because we are using keyword
        get_contract_count();
    }

    // using Person::do_something; // Compiler error
    // because do_something became private in Engineer class from Person class as we inherited privately
    using Engineer::build_something; // ok

private:
    std::string m_speciality{"None"};
};

#endif // CIVIL_ENGINEER_H
