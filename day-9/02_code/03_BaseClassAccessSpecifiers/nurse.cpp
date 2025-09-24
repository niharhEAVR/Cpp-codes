#include "person.h"
#include "nurse.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out , const Nurse& operand){
    out << "Nurse [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() << "]";
    return out;
}
