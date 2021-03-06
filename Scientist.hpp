
#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic
{
    class Scientist : public Player
    {
    private:
        int n;

    public:
        Scientist(Board &board, const int city, int n);
        Scientist &build();
    };
}
