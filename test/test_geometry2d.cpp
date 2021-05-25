

#include "geometry2d.hpp"
#include <iostream>

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE("test_float")
{
  int ret=geometry2d::geometry2d_test<float>(cout);
    REQUIRE(ret == 0);
}


//#include <fstream>

//using namespace std;

//int main(int argc,char** argv) {
		
//	assert(0==geometry2d::geometry2d_test<float>(cout));
//	cout << "geometry2d_test<float> OK" << endl;
//	assert(0==geometry2d::geometry2d_test<double>(cout));
//	cout << "geometry2d_test<double> OK" << endl;
//	assert(0==geometry2d::geometry2d_test<long double>(cout));
//	cout << "geometry2d_test<long double> OK" << endl;
	
//	ofstream areatest("areatest.txt");
//	geometry2d::circle2<double> c={1,0,0.5};
//	geometry2d::circle2<double> C={0,0,1.0};
//	for(C.x=-4.0;C.x<=4.0;C.x+=0.01) areatest << C.x << " " << c.intersection_area(C) << endl;
//	areatest.close();
	
//	return 0;
//}
