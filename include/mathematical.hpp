#pragma once

#include "config.hpp"

namespace geometry2d {

template<typename C=char> std::basic_string<C> version() {return std::basic_string<C>("none");}

template<typename R> R flip(const R x) {return 0==x ? x : -x;}
template<typename R> R sqr(const R x) {return x*x;}
template<typename R> R div(const R n,const R d) {
	assert(R(0)!=d);
	assert(!isnan(d));
	assert(!isinf(d));
	assert(!isnan(n));
	assert(!isinf(n));
	return n/d;
}
template<typename R> R inv(const R x) {
	assert(R(0)!=x);
	assert(!isnan(x));
	assert(!isinf(x));
	return R(1)/x;
}
template<typename R> R length2(const R x,const R y) {return hypot(x,y);}
template<typename R> R normalize2(const R x,const R y) {
	R len=length2(x,y);
	if(len) {
		len=inv(len);
		x*=len;
		y*=len;
	}
}
template<typename R> R dot2(const R x1,const R y1,const R x2,const R y2) {return sqr(x1-x2)+sqr(y1-y2);}
template<typename R> R distance2(const R x1,const R y1,const R x2,const R y2) {return hypot(x1-x2,y1-y2);}



}
