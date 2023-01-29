
#include <boost/test/unit_test.hpp>
#include <state.h>

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_SUITE(TestState)

    using namespace state;

    BOOST_AUTO_TEST_CASE(TestTurns)
    {
        State state(3);
        BOOST_CHECK_EQUAL(state.getCurrentPlayer()->getId(), 0); // First player is id 0
        state.forceEndTurn();
        BOOST_CHECK_EQUAL(state.getCurrentPlayer()->getId(), 1); // Second one is id 1
        state.forceEndTurn();
        BOOST_CHECK_EQUAL(state.getCurrentPlayer()->getId(), 2); // Third one is id 2
        state.forceEndTurn();
        BOOST_CHECK_EQUAL(state.getCurrentPlayer()->getId(), 0); // Goes back to 0
        BOOST_CHECK_EQUAL(state.getNbGeneration(), 2);
    }

    BOOST_AUTO_TEST_CASE(TestPlayers)
    {
        State state(3);
        int idPlayer = 0;
        auto player = state.getSpecificPlayer(idPlayer);
        BOOST_CHECK_EQUAL(player->getId(), idPlayer);
    }

    BOOST_AUTO_TEST_CASE(TestResources)
    {
        State state(3);
        int idPlayer = 0;
        auto player = state.getSpecificPlayer(idPlayer);
        auto resourceBoard = player->getResourceBoard();
        BOOST_CHECK_EQUAL(resourceBoard.isPossibleToModifyResource(GOLD, -1000), false);

        int ironStart = 16;
        int amount = 5;
        resourceBoard.modifyResource(IRON, -amount);
        BOOST_CHECK_EQUAL(resourceBoard.getResourceMap()[IRON], ironStart - amount);

        int heatProd = resourceBoard.getResourceMap()[HEAT_PROD];
        int heatAmount = resourceBoard.getResourceMap()[HEAT];
        resourceBoard.produceResources();
        BOOST_CHECK_EQUAL(resourceBoard.getResourceMap()[HEAT], heatAmount + heatProd);
    }

BOOST_AUTO_TEST_SUITE_END()