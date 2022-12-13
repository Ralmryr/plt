
#include <boost/test/unit_test.hpp>
#include "../../src/shared/state/GlobalParameters.h"
#include "../../src/constants.hpp"



using namespace state;

BOOST_AUTO_TEST_CASE(TestStaticAssert)
{
    GlobalParameters globParam= GlobalParameters();
    BOOST_CHECK_EQUAL(globParam.getNumberOcean(),STARTING_OCEAN);
    BOOST_CHECK_EQUAL(globParam.getOxygen(),MIN_OXYGEN);
    BOOST_CHECK_EQUAL(globParam.getTemp(),MIN_TEMPERATURE);
}

/* vim: set sw=2 sts=2 et : */
