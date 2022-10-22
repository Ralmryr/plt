
#include <boost/test/unit_test.hpp>

#include "../../src/shared/state/Board.h"
#include "../../src/shared/state/AdjacentTo.h"
#include "../../src/shared/state/OnRessource.h"
#include "../../src/shared/state/OnReserved.h"
#include "../../src/shared/state/Player.h"
#include "../../src/shared/state/GlobalParameters.h"
#include "../../src/shared/state/State.h"
#include "../../src/shared/state/Observable.h"
#include "../../src/shared/state/ProjectStd.h"
#include "../../src/shared/state/ProjectCard.h"
#include "../../src/shared/state/RessourceObserver.h"
#include "../../src/shared/state/ParameterObserver.h"


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

BOOST_AUTO_TEST_CASE(TestOnPlayer){
    {
        auto* player = new Player();
        delete player;
    }
}

BOOST_AUTO_TEST_CASE(TestOnGlobalParameters){
    {
        auto* globalParams = new GlobalParameters(0, 0);
        delete globalParams;
    }
}
BOOST_AUTO_TEST_CASE(TestOnState){
    {
        auto* globalParams = new GlobalParameters(0, 0);
        auto* board = new Board();
        auto* state = new State(globalParams, board);
        delete state;
    }
}

BOOST_AUTO_TEST_CASE(TestOnObservable){
    {
        auto* observable = new Observable();
        delete observable;
    }
}

BOOST_AUTO_TEST_CASE(TestOnProjectStd){
    {
        auto* projectStd = new ProjectStd("Ocean", 25);
        delete projectStd;
    }
}

BOOST_AUTO_TEST_CASE(TestOnProjectCard){
    {
        std::vector<Badge> badges {state::ESPACE, state::JOVIEN};
        auto* projectCard = new ProjectCard("Reconversion", 31, "EVENT", badges);
        delete projectCard;
    }
}

BOOST_AUTO_TEST_CASE(TestOnRessourceObserver){
    {
        auto* ressource = new RessourceSTD();
        auto* ressourceObserver = new RessourceObserver(ressource);
        delete ressourceObserver;
    }
}

BOOST_AUTO_TEST_CASE(TestOnParameterObserver){
    {
        auto* globalParams = new GlobalParameters(0, 0);
        auto* paramObserver = new ParameterObserver(globalParams);
        delete paramObserver;
    }
}

/* vim: set sw=2 sts=2 et : */
