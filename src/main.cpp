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
    auto material_glass = make_shared<dielectric>(1.5);
    auto material_bubble = make_shared<dielectric>(1.00 / 1.33); // Air bubble in water

    world.add(make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(0.1, 0.0, -1.7), 0.3, material_center));
    world.add(make_shared<sphere>(point3(-0.65, 0.0, -1.4), 0.5, material_left));
    world.add(make_shared<sphere>(point3(0.8, 0.0, -1.1), 0.5, material_right)); //
    world.add(make_shared<sphere>(point3(0.2, 0.8, -1.1), 0.5, material_top));
    world.add(make_shared<sphere>(point3(0.1, 0.1, -0.8), 0.1, material_bubble));


    // VFOV test
//  auto R = std::cos(pi / 4);

//  auto material_left = make_shared<lambertian>(color(0, 0, 1));
//  auto material_right = make_shared<lambertian>(color(1, 0, 0));

//  world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
//  world.add(make_shared<sphere>(point3(R, 0, -1), R, material_right));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1600;

    cam.samples_per_pixel = 100; // I used 600 samples per pixel for the higher quality diffuse material image
    cam.max_depth = 50; // Maximum ray bounces

    cam.vfov = 20;

    cam.lookfrom = point3(-2, 2, 1);
    cam.lookat = point3(0, 0, -1);

    cam.vup = vec3(0, 1, 0);

    cam.defocus_angle = 7.0;
    cam.focus_dist = 3.4;

    cam.render(world);

    return 0;
}