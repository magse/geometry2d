

#include "geometry2d.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("test_float")
{
  int ret=geometry2d::geometry2d_test<float>(std::cout);
  REQUIRE(ret == 0);
}

TEST_CASE("test_double")
{
  int ret=geometry2d::geometry2d_test<double>(std::cout);
  REQUIRE(ret == 0);
}

TEST_CASE("test_long_double")
{
  int ret=geometry2d::geometry2d_test<long double>(std::cout);
  REQUIRE(ret == 0);
}

