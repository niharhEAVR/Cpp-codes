#include <iostream>
#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"

int main(){

    Person person("Daniel Gray",27,"Blue Sky St 233 #56");
    std::cout << "person : " << person << std::endl;

    std::cout << "---------------" << std::endl;

    Player player;
    player.m_full_name = "Samuel Jackson";
    //player.m_age = 55; Compier error because m_age is protected in Person and not accessible in player
    //player.m_address = "ransom address "; Compiler error because m_address is private in Person and not accessible in Player

    player.play();
    std::cout << "player : " << player << std::endl;

    std::cout << "------------------" << std::endl;

    Nurse nurse;
    // nurse.m_full_name = "Davy Johnes"; Compiler error because nurse inherited from Person in protected mode thats why the public members of Person are protected in Nurse
    // nurse.m_age = 51; // Compiler error

    nurse.treat_unwell_person();
    std::cout << "nurse : " << nurse << std::endl;

    std::cout << "---------------" << std::endl;
    Engineer engineer;
    //engineer.m_full_name = "Olivier Godson"; // Compiler error
    //engineer.m_age = 55; // Compiler error
    //engineer.m_address = "dsakfd;aslfjd;laskf"; // Compiler error

    engineer.build_something();
    std::cout << "engineer : " << engineer << std::endl;
   
    return 0;
}