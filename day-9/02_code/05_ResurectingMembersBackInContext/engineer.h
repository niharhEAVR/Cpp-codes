#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

// Engineer is doing private inheritance

class Engineer : private Person
{
    friend std::ostream &operator<<(std::ostream &out, const Engineer &operand);

public:
    void build_something()
    {
        m_full_name = "John Snow"; // OK
        m_age = 23;                // OK
        // m_address = "897-78-723"; Compiler error
    }
    
    using Person::add;

protected:
    Person::get_address; // you are thinking this line is saved but no error, it will give error on the compiling time
    using Person::get_age;
    using Person::get_full_name;
    // using Person::m_address; // Compiler error

    int get_contract_count() const
    {
        return contract_count;
    }

private:
    int contract_count{0};
};

#endif // ENGINEER_H
