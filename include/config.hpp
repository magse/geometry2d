#pragma once

#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>
#include <string>

#include "version.hpp"

#ifndef EPSTIMES
#define EPSTIMES 60.0
#endif

#ifndef G2D_M_PI
#ifdef _GNU_SOURCE
#define G2D_M_PI M_PIl
#else
#define G2D_M_PI R(3.1415926535897932384626433832795028841971693993751)
#endif
#endif

#ifndef G2D_M_PI_2
#define G2D_M_PI_2 R(1.5707963267948966192313216916397514420985846996876)
#endif

#ifndef G2D_M_PI_4
#define G2D_M_PI_4 R(0.78539816339744830961566084581987572104929234984378)
#endif

#ifndef G2D_M_SQRT1_2
#define G2D_M_SQRT1_2 R(0.70710678118654752440084436210484903928483593768847)
#endif

//TODO: Remove this
template<typename T> T _tbi(T x) {assert(false); return x;}
#define TBI(x) _tbi(x)

