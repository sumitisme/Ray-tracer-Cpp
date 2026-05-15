#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

// C++ std usings

using std::make_shared;
using std::shared_ptr;

// Constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979323846;

// Utility functions

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

// Common headers

#include "color.hpp" 
#include "interval.hpp"
#include "ray.hpp" 
#include "vec3.hpp" 

#endif