#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>
#include <cstdlib>
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

inline double random_double() {
    // Returning a random real number between [0,1)
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // Returns a random real number in [min, max)
    return min + (max - min) * random_double();
}

// Common headers

#include "color.hpp" 
#include "interval.hpp"
#include "ray.hpp" 
#include "vec3.hpp" 

#endif