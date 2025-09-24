#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main(){

    Engineer e1;
    std::cout<< "the addition is: " << e1.add(2,3) << std::endl;
    
    CivilEngineer ce1;
    ce1.build_something();
    ce1.build_road();
   
    return 0;
}