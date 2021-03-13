

#include "geometry2d.hpp"

using namespace std;

int main(int argc,char** argv) {
	
	geometry2d::tests<float>(cout);
	geometry2d::tests<double>(cout);
	geometry2d::tests<long double>(cout);
	
	return 0;
}
