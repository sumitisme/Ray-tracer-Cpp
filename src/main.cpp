#include "../include/vec3.hpp"
#include "../include/color.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    // Image
    int image_width = 256;
    int image_height= 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' <<  image_height << "\n255\n";

    for(int j = 0; j < image_height; j++){
        // For progress report type stuff
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for(int i = 0; i < image_width; i++){

            auto pixel_color = vec3(double(i)/(image_width - 1), double(j)/(image_height - 1), 0);
            write_color(std::cout, pixel_color); // console is the ostream
        }
    }

    std::clog << "\rDone.\n";
    return 0;
}