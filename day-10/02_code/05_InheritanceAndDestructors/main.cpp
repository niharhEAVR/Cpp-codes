#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main(){
   
	Engineer eng1("Daniel Gray",41,"Green Sky Oh Blue 33St#75",12); // you will notice that these destructors will call at the very last
    std::cout<<std::endl;
	CivilEngineer ceng1("Daniel Gray",41,"Green Sky Oh Blue 33St#75",12,"Road Strength");

    return 0;
}