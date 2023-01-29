
#include <boost/test/unit_test.hpp>
#include <state.h>
#include <engine.h>

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

/* ------------------- STATE TEST ------------------ */

BOOST_AUTO_TEST_SUITE(TestState)

    using namespace state;
    using namespace std;

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
        BOOST_CHECK_EQUAL(resourceBoard.isPossibleToModifyResource(GOLD, -10), true);
        std::unordered_map<std::string, std::string> resourceBoardData = {
                {"resource 1", "100"},
                {"resource 2", "16"},
                {"resource 3", "16"},
                {"resource 4", "16"},
                {"resource 5", "16"},
                {"resource 6", "16"},
                {"resource 7", "16"},
                {"resource 8", "16"},
                {"resource 9", "16"},
                {"resource 10", "16"},
                {"resource 11", "16"},
                {"resource 12", "16"},
                {"PV", "0"},
                {"NT", "20"}

        };
        BOOST_TEST_CHECK(resourceBoard.serializeUiData() == resourceBoardData);

        int ironStart = 16;
        int amount = 5;
        resourceBoard.modifyResource(IRON, -amount);
        BOOST_CHECK_EQUAL(resourceBoard.getResourceMap()[IRON], ironStart - amount);

        int heatProd = resourceBoard.getResourceMap()[HEAT_PROD];
        int heatAmount = resourceBoard.getResourceMap()[HEAT];
        resourceBoard.produceResources();
        BOOST_CHECK_EQUAL(resourceBoard.getResourceMap()[HEAT], heatAmount + heatProd);
    }

    BOOST_AUTO_TEST_CASE(TestGlobalParams)
    {
        State state(3);
        auto globalParameters = state.getGlobalParameters();

        unordered_map<string, string> gpData = {
                {"Oxygen", "0"},
                {"Temperature", "-30"},
                {"NumberOceans", "0"}
        };
        BOOST_TEST_CHECK(globalParameters->serializeUiData() == gpData);

        globalParameters->setOxygen(3);
        BOOST_CHECK_EQUAL(globalParameters->getOxygen(), 3);

        globalParameters->setNumberOcean(5);
        BOOST_CHECK_EQUAL(globalParameters->getNumberOcean(), 5);

        globalParameters->setTemp(-16);
        BOOST_CHECK_EQUAL(globalParameters->getTemp(), -16);
    }

BOOST_AUTO_TEST_SUITE_END()

/* ------------------- ENGINE TEST ------------------ */

BOOST_AUTO_TEST_SUITE(TestEngine)

    using namespace std;
    using namespace engine;

    BOOST_AUTO_TEST_CASE(TestEventManager)
    {
        EventManager eventManager;
        BOOST_TEST_CHECK(eventManager.getErrorMessage() == "");
    }

BOOST_AUTO_TEST_SUITE_END()