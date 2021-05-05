
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Scientist.hpp"

using namespace pandemic;

namespace pandemic
{
    Scientist::Scientist(Board &board, const int city, int n) : Player(board, city)
    {
        this->n = n;
    }
}
