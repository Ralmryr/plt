
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/Board.h"
#include "../../src/shared/state/Spot.h"
#include "../../src/shared/state/Tile.h"
#include "../../src/shared/state/CounterPV.h"
//#include "../../src/shared/state/OnReserved.h"
#include "../../src/shared/state/AdjacentTo.h"
#include "../../src/shared/state/OnRessource.h"


using namespace state;

/*BOOST_AUTO_TEST_CASE(TestExemple)
{
  {
    Exemple ex {};
    BOOST_CHECK_EQUAL(ex.x, 0);
    ex.setX(21);
    BOOST_CHECK_EQUAL(ex.x, 21);
  }

  {
    Exemple ex {};
    ex.setX(21);
    BOOST_CHECK_LE(ex.x, 32); // Less than equal
    BOOST_CHECK_GT(ex.x, 11); // Greater than equl
  }
}*/

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestBoard){
    {
        auto* board = new Board();
        auto listSpots = board->getEmptyGrid();
        auto listTiles = board->getOccupiedGrid();
        BOOST_CHECK_EQUAL(listSpots.size(), 61);
        BOOST_CHECK_EQUAL(listTiles.size(), 0);
        delete board;
    }
}


BOOST_AUTO_TEST_CASE(TestSpot){
    {
        auto* spot = new Spot(2, 3);
        BOOST_CHECK_EQUAL(spot->getX(), 2);
        BOOST_CHECK_EQUAL(spot->getX(), 3);
        delete spot;
    }
}


BOOST_AUTO_TEST_CASE(TestTile){
    {
        auto* tile = new Tile();
        delete tile;
    }
}

BOOST_AUTO_TEST_CASE(TestCounterPV){
    {
        auto* counterPV = new CounterPV();

        delete counterPV;
    }
}

/*
BOOST_AUTO_TEST_CASE(testOnReserved){
    {
        auto* onReserved = new OnReserved();
        delete onReserved;
    }
}*/

BOOST_AUTO_TEST_CASE(TestAdjacentTo){
    {
        auto* adjacentTo = new AdjacentTo();
        delete adjacentTo;
    }
}


BOOST_AUTO_TEST_CASE(TestOnRessource){
    {
        auto* onResource = new OnRessource();
        delete onResource;
    }
}


/* vim: set sw=2 sts=2 et : */
