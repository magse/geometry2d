#pragma once

#include "ray2.hpp"

namespace geometry2d {

template<typename R> struct line2 {
	R x1=0;
	R y1=0;
	R x2=1;
	R dy=1;
	// ray2 R edge_distance(const segment2<R>& s) {return TBI(R(0));}
	// vec2 	R closest(const segment2<R>& s,R& t,vec2<R>& p) {return TBI(R(0));}
	// ray2 	void project(const segment2<R>& s,vec2<R>& p1,vec2<R>& p2) {TBI(0);}
	// ray2 	uint32_t intersect(const segment2<R>& c,vec2<R>& p1,vec2<R>& p2) {return TBI(0);}
};

template<typename R> int line2_test(std::ostream& s) {
	return 0;
}

}
