#include <iostream>
#include "person.h"
#include "engineer.h"

int main()
{

	Engineer eng1("cooldude", 69, "nowhere", 43786);
	std::cout << "eng1 : " << eng1 << std::endl;

	std::cout<<std::endl;
	
	Engineer eng2("mercy", 919, "s8ul");
	std::cout << "eng2 : " << eng2 << std::endl;

	std::cout<<std::endl;

	Engineer eng3;
	std::cout << "eng3 : " << eng3 << std::endl;
	
	std::cout<<std::endl;

	Engineer eng4(eng3);
	std::cout << "eng4 : " << eng4 << std::endl;

	return 0;
}