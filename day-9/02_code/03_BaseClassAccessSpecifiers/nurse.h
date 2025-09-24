#ifndef NURSE_H
#define NURSE_H

#include "person.h"

//Nurse will do protected inheritance
class Nurse : protected Person
{
	friend std::ostream& operator<<(std::ostream& , const Nurse& operand);
public:
    void treat_unwell_person(){
        m_full_name = "Mayuri Saha"; // OK
        m_age = 21; // OK
        //m_address = "897-78-723"; Compiler error
    }
};

#endif // NURSE_H
