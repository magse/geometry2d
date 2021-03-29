#pragma once

#include "config.hpp"

namespace geometry2d {

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

// tests
template<typename R> int test_vec2_basic(std::ostream& s) {
	vec2<R> a(-1,-1);
	vec2<R> b(1,1);
	vec2<R> c=a+b;
	assert(c.is_zero());
	assert(R(-2)==a.dot(b));
	return 0;
}

template<typename R> int test_vec2_rotate(std::ostream& s) {
	return 0;
}

}
