#pragma once

#include "circle2.hpp"

namespace geometry2d {

template<typename R> struct ray2 {
	// data
	R x=0;
	R y=0;
	R dx=1;
	R dy=0;
	// constructors
	ray2()=default;
	ray2(const R _x,const R _y,const R _dx,const R _dy) : x(_x),y(_y),dx(_dx),dy(_dy) {normalize(dx,dy);}
	ray2(const vec2<R>& v,const vec2<R>& d) : x(v.x),y(v.y),dx(d.x),dy(d.y) {normalize(dx,dy);}
	// destructor
	virtual ~ray2() {}
	// operations
	vec2<R> normal() {return vec2<R>(y,-x);}
	// advanced operations
	vec2<R> point(const R& t) {return vec2<R>(x+t*dx,y+t*dy);}
	ray2 align(vec2<R>& v) {
		dx=v.x;
		dy=v.y;
		normalize(dx,dy);
	}
	R distance(vec2<R>& v,R& u) {return TBI(R(0));}
	R distance(circle2<R>& c) {return distance(vec2<R>(c.x,c.y));}
	bool interesection(ray2& r,vec2<R>& p,R& u,R& v) {return TBI(false);}
	bool intersect(const circle2<R>& c,vec2<R>& p1,vec2<R>& p2) {return TBI(false);}
	vec2<R> project(const vec2<R>& p) {return TBI(vec2<R>(0,0));}
	ray2 rotate(vec2<R>& v,const R a) {TBI(R(0)); return *this;}
	R closest(const circle2<R>& c,R& t,vec2<R>& p) {
		R dd=sqr(dx)+sqr(dy);
		R d=0;
		t=div(x*dx-dx*c.x+y*dy-dy*c.y,dd);
		d=div(x*dy-y*dx-c.x*dy+c.y*dx,dd);
		p=point(t);
		return d;
	}
	ray2 tangent(circle2<R>& c,const R& a) {TBI(ray2<R>(0,0,0,0)); return *this;}
	// checks
	bool is_paralell(ray2& r) {return TBI(false);}
	bool is_orthogonal(ray2& r) {return TBI(false);}
};

template<typename R> int ray2_test(std::ostream& s) {
	return 0;
}

}
