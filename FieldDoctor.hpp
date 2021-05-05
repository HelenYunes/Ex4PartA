
#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

using namespace pandemic;

namespace pandemic
{
    class FieldDoctor : public Player
    {
    public:
        FieldDoctor(Board &board, const int city);
        FieldDoctor &build();
    };
}
