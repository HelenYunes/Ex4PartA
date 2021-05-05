
#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
namespace pandemic
{
    class OperationsExpert : public Player
    {
    public:
        OperationsExpert(Board &board, const int city);
        OperationsExpert &build();
    };
}
