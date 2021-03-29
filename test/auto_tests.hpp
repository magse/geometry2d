// This file is autogenerated

#include "geometry2d.hpp"
#include <iostream>

#define AUTO_TEST(fcn) res=fcn<R>(s); if(res) return res;

namespace geometry2d {
template<typename R> int auto_tests(std::ostream& s) {
  int res=0;
  AUTO_TEST(test_vec2_basic);
  AUTO_TEST(test_vec2_rotate);
  AUTO_TEST(test_vec2_external);
  return 0;

}
} // namespace geometry2d

// ALL DONE
