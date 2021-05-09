

#include "geometry2d.hpp"

#include <fstream>

using namespace std;

int main(int argc,char** argv) {
		
	geometry2d::geometry2d_test<float>(cout);
	geometry2d::geometry2d_test<double>(cout);
	geometry2d::geometry2d_test<long double>(cout);
	
	ofstream areatest("areatest.txt");
	geometry2d::circle2<double> c={1,0,0.5};
	geometry2d::circle2<double> C={0,0,1.0};
	for(C.x=-4.0;C.x<=4.0;C.x+=0.01) areatest << C.x << " " << c.intersection_area(C) << endl;
	areatest.close();
	
	return 0;
}
