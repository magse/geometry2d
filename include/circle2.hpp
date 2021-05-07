#pragma once

#include "vec2.hpp"

namespace geometry2d {


template<typename R> struct circle2 {
	// data
	R x=0;
	R y=0;
	R r=1;
	// constructors
	circle2()=default;
	circle2(const R a,const R b,const R s) : x(a),y(b),r(s) {}
	circle2(const vec2<R>& v,const R s) : x(v.x),y(v.y),r(s) {}
	// destructor
	virtual ~circle2() {}
	// basic operations
	void operator*(const R& s) {r*=s;}
	void operator/(const R& s) {r/=s;}
	void operator+=(const vec2<R>& v) {x+=v.x; y+=v.y;}
	void operator-=(const vec2<R>& v) {x-=v.x; y-=v.y;}
	void operator*=(const vec2<R>& v) {x*=v.x; y*=v.y;}
	void operator/=(const vec2<R>& v) {x/=v.x; y/=v.y;}
	vec2<R> center() {return vec2<R>(x,y);}
	// advanced operations
	void flipx() {flip(y);}
	void flipy() {flip(x);}
	void flipxy() {flip(x); flip(y);}
	R distance(vec2<R>& v) {return v.distance(center())-r;}
	R distance(circle2& c) {return distance2(x,y,c.x,c.y)-r-c.r;}
	R area() {return R(M_PI)*sqr(r);}
	R area(const R a) {r=sqrt(div(a,R(M_PI)));return r;}
	R diameter() {return R(2)*r;}
	R circumference() {return R(M_2_PI)*r;}
	vec2<R> point(const R a) {return center()+vec2<R>(r*cos(a),r*sin(a));}
	vec2<R> project(const vec2<R>& v) {
//		vec2<R> p=center();
//		R d=distance2(x,y,v.x,v.y);
//		if(0==d) return v;
//		R q=r*(v.x-x)/d;
//		R e=sqr(r)-sqr(q);
//		assert(e>=0);
//		d=x+q-v.x;
//		if(d<(x-q-v.x)) p.x=x+q; else p.x=x-q;
//		p.y=sqrt(e)+y;
		vec2<R> c=vec2<R>(x,y);
		vec2<R> p=v-c;
		if(p.is_zero()) return p;
		p.normalize();
		p=p*r+c;
		return p;
	}
	bool chord(const circle2& c,R& a) {
		// https://mathworld.wolfram.com/Circle-CircleIntersection.html
		if(distance(c)>0) return false;
		if(r<c.r) return c.chord(*this,a);
		if(distance(c.center())<(r-c.r)) return false;
		R d=distance2(x,y,c.x,c.y);
		R d1=div(sqr(d)-sqr(c.r)+sqr(r),R(2)*d);
		R y1=sqrt(sqr(r)-sqr(d1));
		a=R(2)*y1;
		return true;
	}
	bool chord_angle(const circle2& c,R& a) {
		// https://mathworld.wolfram.com/Circle-CircleIntersection.html
		if(distance(c)>0) return false;
		if(r<c.r) return c.chord_angle(*this,a);
		if(distance(c.center())<(r-c.r)) return false;
		R d=distance2(x,y,c.x,c.y);
		R d1=div(sqr(d)-sqr(c.r)+sqr(r),R(2)*d);
		R y1=sqrt(sqr(r)-sqr(d1));
		a=R(2)*atan2(y1,d1);
		return true;
	}
	bool intersect(const circle2& c,vec2<R>& p1,vec2<R>& p2) {
		// https://mathworld.wolfram.com/Circle-CircleIntersection.html
		if(distance(c)>0) return false;
		if(r<c.r) return c.intersect(*this,p1,p2);
		if(distance(c.center())<(r-c.r)) return false;
		R d=distance2(x,y,c.x,c.y);
		R d1=div(sqr(d)-sqr(c.r)+sqr(r),R(2)*d);
		R y1=sqrt(sqr(r)-sqr(d1));
		R a=atan2(y1,d1);
		R v=atan2(c.y-y,c.x-x);
		p1=point(v-a);
		p2=point(v+a);
		return true;
	}
	// checks
	bool is_zero() {return R(0)==r;}
	bool is_unit() {return R(1)==r;}
	bool is_inside(const vec2<R>& v) {return distance(v)<=r;}
	bool is_fully_inside(circle2& c) {
		if(c.r<r) return false;
		R d=distance(c);
		if((d+r)<c.r) return true;
		return false;
	}
	bool is_fully_outside(circle2& c) {
		R d=distance(c);
		if((d-r)>c.r) return true;
		return false;
	}
	bool is_almost_on_edge(const vec2<R>& v,const R tol=R(EPSTIMES)*std::numeric_limits<R>::eps()) {
		return abs(distance(v)-r)<=tol;
	}
};

template<typename R> bool outside_distance(R& dist,circle2<R>& earth,circle2<R>& satellite) {
	dist=0;
	if(earth.is_fully_inside(satellite)) return false;
	dist=earth.distance(satellite);
	return true;
}

template<typename R> int circle2_test(std::ostream& s) {
	circle2<R> e={0,0,20};
	circle2<R> m={0,0,1};
	R d=0;
	outside_distance(d,e,m);
	return 0;
}

}
