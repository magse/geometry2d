// -*- lsst-c++ -*-
#pragma once

#include "vec2.hpp"

namespace geometry2d {

/** @class circle2
 *  @brief A 2D circle
 *  @tparam R floating point type
 *  @details Template class for 2D circle with common properties
 *         can handle intersections and overlapping areas
 */
template<typename R> struct circle2 {
	/// data
	R x=0; ///< x-coordinate of circle
	R y=0; ///< y-coordinate of circle
	R r=1; ///< circle radius
	
	/// default constructor
	circle2()=default;
	/// constructor from scalar values (x,y,r)
	circle2(const R a,const R b,const R s) : x(a),y(b),r(s) {}
	/// constructor from vec2 and radius
	circle2(const vec2<R>& v,const R s) : x(v.x),y(v.y),r(s) {}
	/// destructor
	virtual ~circle2() {}
	/// basic operations
	void operator*(const R& s) {r*=s;}
	void operator/(const R& s) {r/=s;}
	void operator+=(const vec2<R>& v) {x+=v.x; y+=v.y;}
	void operator-=(const vec2<R>& v) {x-=v.x; y-=v.y;}
	void operator*=(const vec2<R>& v) {x*=v.x; y*=v.y;}
	void operator/=(const vec2<R>& v) {x/=v.x; y/=v.y;}
	/// center point of circle
	vec2<R> center() {return vec2<R>(x,y);}
	/// flipping operations
	void flipx() {flip(y);}
	void flipy() {flip(x);}
	void flipxy() {flip(x); flip(y);}
	/// distance between a point v and circle center
	R distance(vec2<R>& v) {return v.distance(center())-r;}
	/// edge-to-edge distance between circles, may be negative
	R distance(circle2& c) {return distance2(x,y,c.x,c.y)-r-c.r;}
	/// checked edge-to-edge distance between circles
	bool outside_distance(R& dist,circle2<R>& satellite) {
		dist=0;
		if(is_fully_inside(satellite)) return false;
		dist=distance(satellite);
		return true;
	}
	/// area of circle
	R area() {return R(G2D_M_PI)*sqr(r);}
	/// sets the radius of the circle according to given area
	R area(const R a) {r=sqrt(div(a,R(G2D_M_PI)));return r;}
	/// diameter of circle
	R diameter() {return R(2)*r;}
	/// circumference of circle
	R circumference() {return R(2)*R(G2D_M_PI)*r;}
	/// point on edge given by angular coordinate
	vec2<R> point(const R a) {return center()+vec2<R>(r*cos(a),r*sin(a));}
	/// projection of point onto circle edge
	vec2<R> project(const vec2<R>& v) {
		vec2<R> c=vec2<R>(x,y);
		vec2<R> p=v-c;
		if(p.is_zero()) return p;
		p.normalize();
		p=p*r+c;
		return p;
	}
	/// return two point (p1 and p2) when the two circles intersect according to boolean return value
	bool intersect(circle2& C,vec2<R>& p1,vec2<R>& p2) {
		if(C.r<r) return C.intersect(*this,p1,p2);
		R d=distance2(x,y,C.x,C.y);
		R ix=div(sqr(d)+sqr(r)-sqr(C.r),R(2)*d);
		if(ix<=-r || ix>=+r) return false;
		R iy=R(0.5)*sqrt(div(-(d-r-C.r)*(d+r-C.r)*(d-r+C.r)*(d+r+C.r),sqr(d)));
		R a=atan2(iy,ix);
		R v=atan2(C.y-y,C.x-x);
		p1=point(v-a);
		p2=point(v+a);
		return true;
	}
	/// return intersection area between two circles, referes to the smaller of them
	R intersection_area(circle2& C) {
		if(C.r<r) return C.intersection_area(*this);
		R d=distance2(x,y,C.x,C.y);
		if(d>=(r+C.r)) return R(0);
		if((d+r)<=C.r) return area();
		R ix=div(sqr(d)+sqr(r)-sqr(C.r),R(2)*d);
		R iy=R(0.5)*sqrt(div(-(d-r-C.r)*(d+r-C.r)*(d-r+C.r)*(d+r+C.r),sqr(d)));
		R a1=atan2(iy,ix);
		R a2=atan2(iy,d-ix);
		R A1=area()*a1/R(G2D_M_PI)-ix*iy;
		R A2=C.area()*a2/R(G2D_M_PI)-(d-ix)*iy;
		return A1+A2;
	}
	/// check if radius is zero
	bool is_zero() {return R(0)==r;}
	/// check if radius is one
	bool is_unit() {return R(1)==r;}
	/// check if a point v is inside the circle
	bool is_inside(const vec2<R>& v) {return distance(v)<=r;}
	/// check if a circle is fully enclosed inside
	bool is_fully_inside(circle2& c) {
		if(c.r<r) return false;
		R d=distance(c);
		if((d+r)<c.r) return true;
		return false;
	}
	/// check if a circle is fully otuside edge
	bool is_fully_outside(circle2& c) {
		R d=distance(c);
		if((d-r)>c.r) return true;
		return false;
	}
	/// check with some tollerance if a point v is on circle edge
	bool is_almost_on_edge(const vec2<R>& v,const R tol=R(EPSTIMES)*std::numeric_limits<R>::eps()) {
		return abs(distance(v)-r)<=tol;
	}
};

/// unit test on intersection functionallity
template<typename R> int circle2_intersection_test(std::ostream& s) {
	circle2<R> C1={0,0,1};
	circle2<R> C2={1,0,1};
	vec2<R> p1;
	vec2<R> p2;
	assert(C1.intersect(C2,p1,p2));
	assert(acceptable_difference<R>(p1.x-R(0.5)));
	assert(acceptable_difference<R>(p1.y+R(0.86602540378443864676372317075293618347140262690519)));
	assert(acceptable_difference<R>(p2.y-R(0.86602540378443864676372317075293618347140262690519)));
	assert(acceptable_difference<R>(C1.intersection_area(C2)-R(1.2283696986087568455447057514333990726600436393449)));
	C2.x=R(1.5);
	assert(C1.intersect(C2,p1,p2));
	assert(acceptable_difference<R>(p1.x-R(0.75)));
	assert(acceptable_difference<R>(p1.y+R(0.66143782776614764762540393840981510642756479577061)));
	assert(acceptable_difference<R>(p2.y-R(0.66143782776614764762540393840981510642756479577061)));
	return 0;
}

/// unit test of circle2 structure
template<typename R> int circle2_test(std::ostream& s) {
	int res=0;
	res+=circle2_intersection_test<R>(s);
	return res;
}

}
