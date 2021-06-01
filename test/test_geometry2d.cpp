

#include "geometry2d.hpp"
#include <iostream>


int main(int argc, char** argv) {
	
	int ret=0;
	
	ret=geometry2d::geometry2d_test<float>(std::cout);
	assert(0==ret);
	
	ret=geometry2d::geometry2d_test<double>(std::cout);
	assert(0==ret);

	ret=geometry2d::geometry2d_test<long double>(std::cout);
	assert(0==ret);

	return 0;
}

