#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"

//Player will do public inheritance from Person
class Player : public Person
{
    friend std::ostream& operator<<(std::ostream& out, const Player& player);
public:
    Player() = default;
    
    //See the access we have to inherited members from Person
    void play(){
        m_full_name = "John Snow"; // OK
        m_age = 55; // OK
        //m_address = "address not need"; Compiler error because m_address is private in Person
    }
};

#endif // PLAYER_H
