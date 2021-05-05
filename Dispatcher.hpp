
#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
using namespace pandemic;
namespace pandemic
{
    class Dispatcher : public Player
    {
    public:
        Dispatcher(Board &board, const int city);
        Dispatcher &build();
    };
}
