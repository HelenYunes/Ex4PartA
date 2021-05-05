

#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        Virologist(Board &board, const int city);
        Virologist &build();
    };
}
