
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace pandemic;

namespace pandemic
{
    FieldDoctor::FieldDoctor(Board &board, const int city) : Player(board, city)
    {
    }
}
