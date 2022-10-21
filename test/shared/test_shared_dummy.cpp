
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Board.h"
#include "../../src/shared/state/AdjacentTo.h"
#include "../../src/shared/state/OnRessource.h"
#include "../../src/shared/state/OnReserved.h"


using namespace state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
  BOOST_CHECK(1);
}


BOOST_AUTO_TEST_CASE(TestBoard){
    {
        auto* board = new Board();
        delete board;
    }
}


BOOST_AUTO_TEST_CASE(TestSpot){
    {
        auto* spot = new Spot(2, 3);
        delete spot;
    }
}


BOOST_AUTO_TEST_CASE(TestTile){
    {
        auto* tile = new Tile(state::FORET);
        delete tile;
    }
}

BOOST_AUTO_TEST_CASE(TestCounterPV){
    {
        auto* counterPV = new CounterPV();

        delete counterPV;
    }
}

BOOST_AUTO_TEST_CASE(testOnReserved){
    {
        auto* onReserved = new OnReserved(true);
        delete onReserved;
    }
}

BOOST_AUTO_TEST_CASE(TestAdjacentTo){
    {
        auto* tile = new Tile(state::CAPITAL);
        auto* adjacentTo = new AdjacentTo(false, tile);
        // The tile is automatically deleted in the adjacentTo destructor
        delete adjacentTo;
    }
}


BOOST_AUTO_TEST_CASE(TestOnRessource){
    {
        std::vector<Ressource*> resVector {new RessourceSTD(), new RessourceSTD()};
        auto* onResource = new OnRessource(resVector);
        // The vector of Ressource pointers is automatically cleaned
        delete onResource;
    }
}
/* vim: set sw=2 sts=2 et : */
