//
// Created by aminjon on 7/28/22.
//

#define BOOST_TEST_MODULE helloworld_test_module

#include "lib.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(hello_test_suite)

BOOST_AUTO_TEST_CASE(hello_test_version) {
    BOOST_CHECK(lib::version() > 0);
}

BOOST_AUTO_TEST_SUITE_END()