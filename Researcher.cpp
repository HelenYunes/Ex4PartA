
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Researcher.hpp"

using namespace pandemic;

namespace pandemic
{
    Researcher::Researcher(Board &board, const int city) : Player(board, city)
    {
    }
}
