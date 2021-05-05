
#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;

namespace pandemic
{
    class Medic : public Player
    {
    public:
        Medic(Board &board, const int city);
        Medic &build();
    };
}
