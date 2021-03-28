#pragma once

#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>
#include <string>

#define GEOMETRY2D_VERSION_MAJOR 0
#define GEOMETRY2D_VERSION_MINOR 0

#ifndef EPSTIMES
#define EPSTIMES 10.0
#endif

template<typename T> T _tbi(T x) {assert(false); return x;}
#define TBI(x) _tbi(x)

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

template<typename R> struct vec2 {
	// data
	R x=0;
	R y=0;
	// constructors
	vec2()=default;
	vec2(const R a,const R b) : x(a),y(b) {}
	vec2(const vec2& v) : x(v.x),y(v.y) {}
	vec2(float* p) {
		x=static_cast<R>(*p);
		y=static_cast<R>(*(p+1));
	}
	vec2(double* p) {
		x=static_cast<R>(*p);
		y=static_cast<R>(*(p+1));
	}
	vec2(long double* p) {
		x=static_cast<R>(*p);
		y=static_cast<R>(*(p+1));
	}
	// destructor
	virtual ~vec2() {}
	// basic operations
	vec2 operator+(const vec2& v) {return vec2(x+v.x,y+v.y);}
	vec2 operator-(const vec2& v) {return vec2(x-v.x,y-v.y);}
	vec2 operator*(const vec2& v) {return vec2(x*v.x,y*v.y);}
	vec2 operator/(const vec2& v) {return vec2(x/v.x,y/v.y);}
	vec2 operator*(const R& s) {return vec2(x*s,y*s);}
	vec2 operator/(const R& s) {return vec2(x/s,y/s);}
	vec2 operator+() {return *this;}
	vec2 operator-() {return vec2(-x,-y);}
	void operator+=(const vec2& v) {x+=v.x; y+=v.y;}
	void operator-=(const vec2& v) {x-=v.x; y-=v.y;}
	void operator*=(const vec2& v) {x*=v.x; y*=v.y;}
	void operator/=(const vec2& v) {x/=v.x; y/=v.y;}
	// advanced operations
	R dot(const vec2& v) {return x*v.y+y*v.x;}
	R dot() {return dot(*this);}
	R length() {return sqrt(dot());}
	void rotate(const R a) {R c=cos(a); R s=sin(a); R xx=x*c-y*s; y=x*s+y*c; x=xx;}
	void rotate(const R ax,const R ay) {R xx=x*ax-y*ay; y=x*ay+y*ax; x=xx;}
	void flipx() {flip(y);}
	void flipy() {flip(x);}
	void flipxy() {flip(x); flip(y);}
	void normalize() {normalize2(x,y);}
	R distance(const vec2& v) {return length(sqr(v.x-x),sqr(v.y-y));}
	R angle(const vec2& v) {return atan2(y-v.y,x-v.x);}
	void direction(const R a) {x=cos(a); y=sin(a);}
	// checks
	bool is_zero() {
		if(R(0)!=x) return false;
		return R(0)==y;
	}
	bool is_unit() {
		if(R(1)!=x) return false;
		return R(1)==y;
	}
	bool is_almost_zero(const R tol=R(EPSTIMES)*std::numeric_limits<R>::eps()) {
		return abs(x)<=tol && abs(y)<=tol;
	}
};

template<typename R> vec2<R> operator*(const R& s,const vec2<R>& v) {return vec2<R>(s*v.x,s*v.y);}
template<typename R> vec2<R> rotate(const vec2<R>& v,const R a) {vec2<R> r=v; r.rotate(a); return r;}
template<typename R> vec2<R> rotate(const vec2<R>& v,const R ax,const R ay) {vec2<R> r=v; r.rotate(ax,ay); return r;}
template<typename R> R distance(const vec2<R>& a,const vec2<R>& b) {return a.distance(b);}
template<typename R> R dot(const vec2<R>& a,const vec2<R>& b) {return a.dot(b);}
template<typename R> vec2<R> direction(const R a) {return vec2<R>(cos(a),sin(a));}

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
	R distance(const vec2<R>& v) {return v.distance(center())-r;}
	R distance(const circle2& c) {return distance2(x,y,c.x,c.y)-r-c.r;}
	R area() {return R(M_PI)*sqr(r);}
	R area(const R a) {r=sqrt(div(a,R(M_PI)));return r;}
	R diameter() {return R(2)*r;}
	R circumference() {return R(M_2_PI)*r;}
	vec2<R> project(const vec2<R>& v) {
		vec2<R> p=center();
		R d=distance2(x,y,v.x,v.y);
		if(0==d) return v;
		R q=r*(v.x-x)/d;
		R e=sqr(r)-sqr(q);
		assert(e>=0);
		d=x+q-v.x;
		if(d<(x-q-v.x)) p.x=x+q; else p.x=x-q;
		p.y=sqrt(e)+y;
		return p;
	}
	bool intersect(const circle2& c,vec2<R>& p1,vec2<R>& p2) {return TBI(false);}
	// checks
	bool is_zero() {return R(0)==r;}
	bool is_unit() {return R(1)==r;}
	bool is_inside(vec2<R>& v) {return distance(v)<=r;}
	bool is_almost_on_edge(const vec2<R>& v,const R tol=R(EPSTIMES)*std::numeric_limits<R>::eps()) {
		return abs(distance(v)-r)<=tol;
	}
};

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

template<typename R> struct segment2 {
	R x1=0;
	R y1=0;
	R x2=1;
	R dy=1;
	// ray2 R edge_distance(const segment2<R>& s) {return TBI(R(0));}
	// vec2 	R closest(const segment2<R>& s,R& t,vec2<R>& p) {return TBI(R(0));}
	// ray2 	void project(const segment2<R>& s,vec2<R>& p1,vec2<R>& p2) {TBI(0);}
	// ray2 	uint32_t intersect(const segment2<R>& c,vec2<R>& p1,vec2<R>& p2) {return TBI(0);}
};

// tests
template<typename R> int test1(std::ostream& s) {
	vec2<R> a(-1,-1);
	vec2<R> b(1,1);
	vec2<R> c=a+b;
	assert(c.is_zero());
	assert(R(-2)==a.dot(b));
	s << "test1<" << sizeof(R) << "> OK" << std::endl;
	return 0;
}

template<typename R> int tests(std::ostream& s) {
	int res=0;
	res+=test1<R>(s);
	return res;
}

}
