

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace std;
using namespace pandemic;

namespace pandemic
{
    Player::Player(Board &board, const int city)
    {
        this->cards = 0;
        this->research_stations = 0;
    }
    Player::~Player() {}
    Player &Player::take_card(const int city)
    {
        return *this;
    }
    Player &Player::drive(const int city)
    {
        return *this;
    }
    Player &Player::fly_direct(const int city)
    {
        return *this;
    }
    Player &Player::fly_charter(const int city)
    {
        return *this;
    }
    Player &Player::fly_shuttle(const int city)
    {
        return *this;
    }
    Player &Player::bulid()
    {
        return *this;
    }
    Player &Player::discover_cure(const int color)
    {
        return *this;
    }
    Player &Player::treat(const int city)
    {
        return *this;
    }
    Player &Player::remove_cards()
    {
        return *this;
    }
    string Player::role() const
    {
        return "play";
    }
}
