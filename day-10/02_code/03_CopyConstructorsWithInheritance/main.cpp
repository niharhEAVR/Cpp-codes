#include <iostream>
#include "person.h"
#include "engineer.h"
#include "civilengineer.h"

int main()
{

	Engineer eng1("Daniel Gray",41,"Green Sky Oh Blue 33St#75",12);

	std::cout << "----------\n" <<  std::endl;
	
	Engineer eng2(eng1);
	std::cout << "eng2 : " << eng2 << std::endl;

	std::cout << "----------\n" <<  std::endl;

	CivilEngineer ceng1("Daniel Gray", 41, "Green Sky Oh Blue 33St#75", 123456, "Road Strength");

	std::cout << "----------\n" << std::endl;
	
	CivilEngineer ceng2(ceng1);
	std::cout << "eng2 : " << ceng2 << std::endl;

	std::cout << "----------\n" << std::endl;

	CivilEngineer ceng3("cooldude", 69, "nowhere", 91969, "bak bak");

	return 0;
}