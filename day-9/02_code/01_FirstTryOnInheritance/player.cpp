#include "person.h"
#include "player.h"

Player::Player(std::string_view game_param) : m_game(game_param)
{
    // first_name = "John"; It will give Compiler errors because first_name and last_name are private members of Person class 
    // last_name = "Snow";
}

std::ostream &operator<<(std::ostream &out, const Player &player)
{

    out << "Player : [ game : " << player.m_game
        << " || name : " << player.get_first_name()
        << " " << player.get_last_name() << "]";
    return out;
}