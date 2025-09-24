#include "person.h"
#include "engineer.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out , const Engineer& operand){
     out << "Engineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() << "]";
    return out;   
}
