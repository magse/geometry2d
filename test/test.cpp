

#include "geometry2d.hpp"

using namespace std;

int main(int argc,char** argv) {
		
	geometry2d::geometry2d_test<float>(cout);
	geometry2d::geometry2d_test<double>(cout);
	geometry2d::geometry2d_test<long double>(cout);
	
	return 0;
}
