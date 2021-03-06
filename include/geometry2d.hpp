#pragma once

#include "geometry2d/vec2.hpp"
#include "geometry2d/circle2.hpp"
#include "geometry2d/ray2.hpp"
#include "geometry2d/line2.hpp"

#include <iostream>

namespace geometry2d {

template<typename R> int geometry2d_test(std::ostream& s=std::cout) {
	int result=0;
	result|=vec2_test<R>(s);
	result|=circle2_test<R>(s);
	result|=ray2_test<R>(s);
	result|=line2_test<R>(s);
	return result;
}

}
