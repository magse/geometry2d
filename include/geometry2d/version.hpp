#pragma once

#define GEOMETRY2D_VERSION_MAJOR 0
#define GEOMETRY2D_VERSION_MINOR 0

#include <string>

namespace geometry2d {

template<typename C=char> std::basic_string<C> version() {return std::basic_string<C>("none");}

}

