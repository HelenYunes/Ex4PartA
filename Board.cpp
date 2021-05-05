#include "Board.hpp"
#include "City.hpp"

using namespace pandemic;

namespace pandemic
{
    Board::Board()
    {
    }
    Board::~Board() {}
    bool Board::is_clean()
    {
        for (int i = 0; i < ALL_CITIES; i++)
        {
            if (table[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    ostream &operator<<(ostream &out, const Board &board)
    {
        out << "To be continued";
        return out;
    }
    int &Board::operator[](int city)
    {
        return table[city];
    }

    void Board::remove_cures()
    {
    }
    void Board::remove_stations()
    {
    }
}
