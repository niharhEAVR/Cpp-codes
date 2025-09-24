#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H
#include "engineer.h"

class CivilEngineer : public Engineer
{
    friend std::ostream& operator<<(std::ostream&, const CivilEngineer& operand);
public:
    void build_road(){
        //get_full_name(); // Compiler error
        ///m_full_name = "Daniel Gray"; //Compiler error
        //m_age = 45; // Compiler error

        // because CivilEngineer is derived from Engineer in public mode and Engineer is derived from Person in private mode
        // so all the public and protected members of Person are private in Engineer and not accessible in CivilEngineer
    }
	
private : 
    std::string m_speciality{"None"};

};

#endif // CIVIL_ENGINEER_H
