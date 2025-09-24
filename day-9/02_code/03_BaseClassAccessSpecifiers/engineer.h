#ifndef ENGINEER_H
#define ENGINEER_H
#include "person.h"

//Engineer is doing private inheritance

class Engineer : private Person
{
friend std::ostream& operator<<(std::ostream& out , const Engineer& operand);
public:
    
    void build_something(){
        m_full_name = "Bikash"; // OK
        m_age = 33; // OK
        //m_address = "897-78-723"; Compiler error
    }
    
};

#endif // ENGINEER_H
