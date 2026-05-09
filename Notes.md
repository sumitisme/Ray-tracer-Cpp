# Overview / Intro:

We will create a .ppm file as an output. In a .ppm file:
* The pixels are written out in rows.
* Every row of pixels is written out left to right
* These rows are written out from top to bottom
* By convention, each of the red/green/blue components are represented internally by real-valued variables that range from 0.0 to 1.0. These must be scaled to integer values between 0 and 255 before we print them out.
<br>

### Note: for other file-formats, use stb_image.h

### Note: for output logs, we can't really use std::cout since we will use that for the .ppm file. We can, however, use std::clog to log the output stream. So, we will use that.

# The vec3.hpp file

It has the following capabilities:
* In the constructor:
    - It initializes the 3d vector as 0, 0, 0
* Has functions that return the value of x, y, z elements of the vector.
* Has overloaded operators:
    - -, [], +=, *=, /=, <<, a + b, a - b, a * b, constant * a, constant / a
* Has other helpful functions like:
    - length(), length_squared(), dot, cross, unit_vector

# The color.hpp file

Has a function that writes color to the output after converting the 0 to 1 value to 0 to 255 version

# The main.cpp file