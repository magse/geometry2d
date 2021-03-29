#pragma once

#include "mathematical.hpp"

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
	R dot(const vec2& v) {return x*v.x+y*v.y;}
	R dot() {return dot(*this);}
	R length() {return sqrt(dot());}
	void rotate(const R a) {R c=cos(a); R s=sin(a); R xx=x*c-y*s; y=x*s+y*c; x=xx;}
	void rotate(const R ax,const R ay) {R xx=x*ax-y*ay; y=x*ay+y*ax; x=xx;}
	void flipx() {flip(y);}
	void flipy() {flip(x);}
	void flipxy() {flip(x); flip(y);}
	void normalize() {normalize2(x,y);}
	R distance(const vec2& v) {return length2(v.x-x,v.y-y);}
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
template<typename R> R distance(vec2<R>& a,vec2<R>& b) {return a.distance(b);}
template<typename R> R dot(vec2<R>& a,vec2<R>& b) {return a.dot(b);}
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
	vec2<R> v(R(1),R(0));
	v.rotate(static_cast<R>(G2D_M_PI_4));
	R d=abs(v.x-G2D_M_SQRT1_2);
	// TODO:  assert(d<=EPSTIMES*std::numeric_limits<R>::epsilon());
	return 0;
}

template<typename R> int test_vec2_external(std::ostream& s) {
	vec2<R> v1(R(1),R(0));
	vec2<R> v2=v1;
	v2.rotate(R(G2D_M_PI_2));
	R d=dot(v1,v2);
	// TODO:  assert(abs(d)<=EPSTIMES*std::numeric_limits<R>::epsilon());
	assert(distance(v1,v2));
	return 0;
}

template<typename R> int test_vec2_constructors(std::ostream& s) {
    float fv[]={1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f};
    float dv[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    float lv[]={1.0l,2.0l,3.0l,4.0l,5.0l,6.0l,7.0l,8.0l};
    vec2<R> v;
    for(size_t n=0;n<4;n++) {
        v+=vec2<R>(&fv[2*n]);
        v+=vec2<R>(&dv[2*n]);
        v+=vec2<R>(&lv[2*n]);
    }
    vec2<R> p=v;
    vec2<R> q(1,1);
    for(size_t n=0;n<4;n++) {
        v-=vec2<R>(&fv[2*n]);
        v-=vec2<R>(&dv[2*n]);
        v-=vec2<R>(&lv[2*n]);
    }
    return 0;
}

template<typename R> int test_vec2_math(std::ostream& s) {
    vec2<R> a,b,c,d;
    R g=1.2;
    a=vec2<R>(1,2);
    b=vec2<R>(4,4);
    a+=a*g;
    a+=a*b;
    a+=b*a;
    a+=g*a;
    c=vec2<R>(3,3);
    d=vec2<R>(4,4);
    a=c/-d;
    return 0;
}

}
