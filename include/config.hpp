#pragma once

#include <iostream>
#include <limits>
#include <cassert>
#include <cmath>
#include <string>

#include "version.hpp"

#ifndef EPSTIMES
#define EPSTIMES 10.0
#endif

template<typename T> T _tbi(T x) {assert(false); return x;}
#define TBI(x) _tbi(x)

