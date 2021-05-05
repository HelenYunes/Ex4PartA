
#pragma once

#include "Color.hpp"
#include <iostream>
#include <map>

using namespace std;

namespace pandemic
{
    class Board
    {
        const unsigned int ALL_CITIES = 48;

    private:
        map<int, int> table;

    public:
        Board();
        ~Board();
        bool is_clean();
        void remove_cures();
        void remove_stations();
        int &operator[](int city);
        friend ostream &operator<<(ostream &out, const Board &board);
    };
}
