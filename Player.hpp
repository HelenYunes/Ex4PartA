
#pragma once

#include "Board.hpp"
#include "Color.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic
{
    class Player
    {
    private:
        Board board;
        int current_city;
        unsigned int cards;
        char research_stations;

    public:
        Player(Board &board, const int city);
        ~Player();
        virtual Player &bulid();
        virtual Player &discover_cure(const int color);
        virtual Player &treat(const int city);
        virtual Player &drive(const int city);
        virtual Player &fly_direct(const int city);
        virtual Player &fly_charter(const int city);
        virtual Player &fly_shuttle(const int city);
        virtual Player &take_card(const int city);
        virtual Player &remove_cards();
        string role() const;
    };
}
