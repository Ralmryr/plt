
#include <boost/test/unit_test.hpp>
#include <state.h>

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    BOOST_CHECK(1);
}

BOOST_AUTO_TEST_CASE(TestState)
{
    {
        using namespace state;
        State state(5);
        BOOST_CHECK_EQUAL(state.getCurrentPlayer()->getId(), 0);
    }
}
