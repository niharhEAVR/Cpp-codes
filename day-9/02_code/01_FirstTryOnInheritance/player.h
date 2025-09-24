#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include "person.h"

class Player : public Person
{
    friend std::ostream &operator<<(std::ostream &out, const Player &player);

public:
    Player() = default;
    Player(std::string_view game_param);

private:
    std::string m_game{"None"};
};
