
#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        GeneSplicer(Board &board, const int city);
        GeneSplicer &build();
    };
}
