#include "../include/constants.hpp"

#include "../include/hittable.hpp"
#include "../include/hittable_list.hpp"
#include "../include/sphere.hpp"
#include "../include/camera.hpp"
#include "../include/material.hpp"


int main(int argc, char* argv[]) {

    hittable_list world; // The name of the list itself is world

    auto material_ground = make_shared<lambertian>(color(0.5, 0.5, 0.5));
    auto material_center = make_shared<metal>(color(0.1, 0.2, 0.5), 0.0);
    auto material_left = make_shared<metal>(color(0.8, 0.8, 0.8), 0.3);
    auto material_right = make_shared<metal>(color(0.8, 0.8, 0.8), 0.0);
    auto material_top = make_shared<metal>(color(0.8, 0.4, 0.2), 0.0);

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.3, 0.0, -2.6), 0.5, material_center));
    world.add(make_shared<sphere>(point3(-0.5, 0.0, -1.4), 0.5, material_left));
    world.add(make_shared<sphere>(point3(0.8, 0.0, -1.1), 0.5, material_right));
    world.add(make_shared<sphere>(point3(0.2, 0.8, -1.1), 0.5, material_top));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1600;

    cam.samples_per_pixel = 100; // I used 600 samples per pixel for the higher quality diffuse material image
    cam.max_depth = 50; // Maximum ray bounces

    cam.render(world);

    return 0;
}