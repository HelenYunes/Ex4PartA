#include <iostream>
#include <stdexcept>

#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Medic.hpp"
#include "Scientist.hpp"
#include "Virologist.hpp"
#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

TEST_CASE("Operator []")

{

    Board board;

    CHECK_NOTHROW(board[Algiers] = 1);

    CHECK_EQ(board[Algiers], 1);

    CHECK_NOTHROW(board[Atlanta] = 2);

    CHECK_EQ(board[Atlanta], 2);

    CHECK_NOTHROW(board[Baghdad] = 0);

    CHECK_EQ(board[Baghdad], 0);

    CHECK_NOTHROW(board[Bogota] = 1);

    CHECK_EQ(board[Bogota], 1);

    CHECK_NOTHROW(board[Chennai] = 2);

    CHECK_EQ(board[Chennai], 2);

    CHECK_NOTHROW(board[Delhi] = 0);

    CHECK_EQ(board[Delhi], 0);

    CHECK_NOTHROW(board[HongKong] = 1);

    CHECK_EQ(board[HongKong], 1);

    CHECK_NOTHROW(board[Karachi] = 2);

    CHECK_EQ(board[Karachi], 2);

    CHECK_NOTHROW(board[Lima] = 0);

    CHECK_EQ(board[Lima], 0);

    CHECK_NOTHROW(board[Madrid] = 1);

    CHECK_EQ(board[Madrid], 1);

    CHECK_NOTHROW(board[MexicoCity] = 2);

    CHECK_EQ(board[MexicoCity], 2);

    CHECK_NOTHROW(board[Milan] = 0);

    CHECK_EQ(board[Milan], 0);

    CHECK_NOTHROW(board[Mumbai] = 1);

    CHECK_EQ(board[Mumbai], 1);

    CHECK_NOTHROW(board[Paris] = 2);

    CHECK_EQ(board[Paris], 2);

    CHECK_NOTHROW(board[SanFrancisco] = 0);

    CHECK_EQ(board[SanFrancisco], 0);
}
TEST_CASE("Test FieldDoctor")
{
    Board board;
    FieldDoctor fieldDoctor{board, NewYork};
    CHECK_THROWS(fieldDoctor.treat(NewYork));
    CHECK_NOTHROW(board[NewYork] = 6);
    CHECK(board[NewYork] == 6);
    CHECK_NOTHROW(fieldDoctor.treat(NewYork));
    //field doctor can treat in any city near the city he is in
    CHECK(board[NewYork] == 5);
    CHECK_NOTHROW(board[Montreal] = 6);
    CHECK(board[Montreal] == 6);
    CHECK_NOTHROW(fieldDoctor.treat(Montreal));
    CHECK(board[Montreal] == 5);
    CHECK_NOTHROW(fieldDoctor.drive(Washington));
    CHECK_NOTHROW(board[Washington] = 6);
    CHECK(board[Washington] == 6);
    CHECK_NOTHROW(fieldDoctor.treat(Washington));
    CHECK(board[Washington] == 5);
    CHECK_NOTHROW(fieldDoctor.drive(London));
    CHECK_NOTHROW(board[London] = 6);
    CHECK(board[London] == 6);
    CHECK_NOTHROW(fieldDoctor.treat(London));
    CHECK(board[London] == 5);
    CHECK_NOTHROW(fieldDoctor.drive(Madrid));
    CHECK_NOTHROW(board[Madrid] = 6);
    CHECK(board[Madrid] == 6);
    CHECK_NOTHROW(fieldDoctor.treat(Madrid));
    CHECK(board[Madrid] == 5);
}
TEST_CASE("Test Virologist")
{
    Board board;
    Virologist virologist{board, Madrid};
    //can't treat without cards
    CHECK_THROWS(virologist.treat(Manila));
    board[Manila] = 1;
    CHECK(board[Manila] == 1);
    //virlogist can treat in any city
    CHECK_NOTHROW(virologist.take_card(Manila).treat(Manila));
    CHECK(board[Manila] == 0);
    CHECK_THROWS(virologist.take_card(Manila).treat(Manila));
}
TEST_CASE("Medic")

{
    Board board;
    Medic medic{board, LosAngeles};
    //can't treat without cards
    CHECK_THROWS(medic.treat(LosAngeles));
    medic.take_card(LosAngeles);
    board[LosAngeles] = 5;
    CHECK(board[LosAngeles] == 5);
    CHECK_NOTHROW(medic.treat(LosAngeles));
    //medic can removes all the disease cubes
    CHECK(board[LosAngeles] == 0);
}
TEST_CASE("Dispatcher")
{
    Board board;
    Dispatcher dispatcher{board, LosAngeles};
    CHECK_NOTHROW(dispatcher.take_card(LosAngeles));
    CHECK_NOTHROW(dispatcher.build());
    //dispatcher can fly direct without card
    CHECK_NOTHROW(dispatcher.fly_direct(Chicago));
    //can't build without cards
    CHECK_THROWS(dispatcher.build());
    CHECK_NOTHROW(dispatcher.take_card(Chicago));
    CHECK_NOTHROW(dispatcher.build());
}
TEST_CASE("GeneSplicer")
{
    Board board;
    board[Algiers] = 1;
    GeneSplicer geneSplicer(board, Algiers);
    CHECK_NOTHROW(geneSplicer.take_card(Paris).take_card(Khartoum).take_card(Cairo).take_card(Lagos).take_card(Beijing));
    //gene splicer can discover cure with different color cards
    CHECK_NOTHROW(geneSplicer.discover_cure(Black););
}
TEST_CASE("OperationsExpert")
{
    Board board;
    OperationsExpert operations_expert{board, Miami};
    //operations expert can build without a card
    CHECK_NOTHROW(operations_expert.build());
    CHECK_NOTHROW(operations_expert.drive(Bogota));
    CHECK_NOTHROW(operations_expert.build());
}
TEST_CASE("Researcher")
{
    Board board;
    board[Moscow] = 5;
    Researcher researcher(board, Moscow);
    Medic medic(board, Moscow);
    //can't discover cure without cards
    CHECK_THROWS(researcher.discover_cure(Black));
    CHECK_NOTHROW(researcher.take_card(Algiers).take_card(Baghdad).take_card(Chennai).take_card(Delhi).take_card(Kolkata));
    CHECK_EQ(board[Moscow], 5);
    //researcher can discover cure in a city where there is no station
    CHECK_NOTHROW(researcher.discover_cure(Black).treat(Moscow));
    CHECK_EQ(board[Moscow], 0);
}

TEST_CASE("Scientist")
{
    Board board;
    Scientist scientist{board, Chicago, 3};
    CHECK_THROWS(scientist.discover_cure(Black));
    CHECK_THROWS(scientist.discover_cure(Blue));
    CHECK_THROWS(scientist.discover_cure(Red));
    CHECK_THROWS(scientist.discover_cure(Yellow));
    scientist.take_card(Chicago);
    //scientist1.build();
    CHECK_NOTHROW(scientist.take_card(Chicago).take_card(Essen).take_card(London));
    //scientist can discover cure wit less than 5 cards
    CHECK_NOTHROW(scientist.discover_cure(Blue));
}
