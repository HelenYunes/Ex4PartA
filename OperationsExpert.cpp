
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace pandemic;

namespace pandemic
{
    OperationsExpert::OperationsExpert(Board &board, const int city) : Player(board, city)
    {
    }
    OperationsExpert &OperationsExpert::build()
    {
        return *this;
    }
}
