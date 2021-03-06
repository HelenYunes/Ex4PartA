
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

using namespace pandemic;

namespace pandemic
{
    Virologist::Virologist(Board &board, const int city) : Player(board, city)
    {
    }
}
