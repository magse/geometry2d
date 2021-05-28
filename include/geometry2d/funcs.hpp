#pragma once

#include "defs.hpp"

namespace geometry2d {

//template<typename C=char> std::basic_string<C> version() {return std::basic_string<C>("none");}

template<typename R> R flip(const R x) {return 0==x ? x : -x;}

template<typename R> R sqr(const R x) {return x*x;}

template<typename R> R div(const R n,const R d) {
	assert(R(0)!=d);
	assert(!std::isnan(d));
	assert(!std::isinf(d));
	assert(!std::isnan(n));
	assert(!std::isinf(n));
	return n/d;
}

template<typename R> R inv(const R x) {
	assert(R(0)!=x);
	assert(!std::isnan(x));
	assert(!std::isinf(x));
	return R(1)/x;
}

template<typename R> R length2(const R x,const R y) {return hypot(x,y);}

template<typename R> R normalize2(R& x,R& y) {
	R len=length2(x,y);
	if(len) {
		len=inv(len);
		x*=len;
		y*=len;
	}
	return len;
}

template<typename R> R dot2(const R x1,const R y1,const R x2,const R y2) {return x1*x2+y1*y2;}

template<typename R> R distance2(const R x1,const R y1,const R x2,const R y2) {return hypot(x1-x2,y1-y2);}

template<typename R> bool acceptable_difference(const R e) {
	return abs(e)<static_cast<R>(10)*std::numeric_limits<R>::epsilon();
}
template<> bool acceptable_difference<long double>(const long double e) {
	return abs(e)<static_cast<long double>(1.0e-16);
}

}
