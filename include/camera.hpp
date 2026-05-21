#ifndef CAMERA_H
#define CAMERA_H

#include "constants.hpp"
#include "hittable.hpp"
#include "material.hpp"

class camera {
    public:
    double aspect_ratio = 1.0;
    int image_width = 100;
    int samples_per_pixel = 10; // Count of random samples for each pixel
    int max_depth = 50; // Limiting the maximum number of ray bounces to 50

    double vfov = 90; // Vertical FOV
    point3 lookfrom = point3(0, 0, 0);
    point3 lookat = point3(0, 0, -1);
    
    vec3 vup = vec3(0, 1, 0);

    double defocus_angle = 0;
    double focus_dist = 0;

    void render(const hittable& world) {
        initialize();

        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for(int j = 0; j < image_height; j++) {
            std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            for(int i = 0; i < image_width; i++) {
//              auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
//              auto ray_direction = pixel_center - center;
//              ray r(center, ray_direction);

//              color pixel_color = ray_color(r, world);
//              write_color(std::cout, pixel_color);

                color pixel_color(0, 0, 0);
                for(int sample = 0; sample < samples_per_pixel; sample++) {
                    ray r = get_ray(i, j);
                    pixel_color += ray_color(r, max_depth, world);
                }
                write_color(std::cout, pixel_samples_scale * pixel_color);
            }
        }
    }

    private:
    int image_height;
    double pixel_samples_scale; // Color scale factor for a sum of pixel samples
    point3 center;
    point3 pixel00_loc;
    vec3 pixel_delta_u;
    vec3 pixel_delta_v;
    vec3 u, v, w;

    vec3 defocus_disk_u;
    vec3 defocus_disk_v;

    void initialize() {
        image_height = int(image_width / aspect_ratio);
        image_height = (image_height < 1) ? 1 : image_height;

        pixel_samples_scale = 1.0 / samples_per_pixel;

        center = lookfrom;

        // Viewport dimensions
//      auto focal_length = (lookfrom - lookat).length();
        auto theta = degrees_to_radians(vfov);
        auto h = std::tan(theta / 2);
        auto viewport_height = 2 * h * focus_dist;
        auto viewport_width = viewport_height * (double(image_width) / image_height);

        // Calculating the u, v, w unit basis vectors for the camera coordinate frame
        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        auto viewport_u = viewport_width * u;
        auto viewport_v = viewport_height * -v;

        pixel_delta_u = viewport_u / image_width;
        pixel_delta_v = viewport_v / image_height;

        // Upper left pixel
        auto viewport_upper_left = center - (focus_dist * w) - viewport_u / 2 - viewport_v / 2;

        pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        auto defocus_radius = focus_dist * std::tan(degrees_to_radians(defocus_angle / 2));
        defocus_disk_u = u * defocus_radius;
        defocus_disk_v = v * defocus_radius;
    }

    ray get_ray(int i, int j) const {
        auto offset = sample_square();
        auto pixel_sample = pixel00_loc + ((i + offset.x()) * pixel_delta_u) + ((j + offset.y()) * pixel_delta_v);

        auto ray_origin = (defocus_angle <= 0) ? center : defocus_disk_sample();
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction);
    }

    vec3 sample_square() const {
        // Returns the vector to a random point in the [-.5, -.5] - [+.5, +.5] unit square.
        return vec3(random_double() - 0.5, random_double() - 0.5, 0);
    }

    point3 defocus_disk_sample() const {
        // returns a random point in the camera defocus disk

        auto p = random_in_unit_disk();
        return center + (p[0] * defocus_disk_u) + (p[1] * defocus_disk_v);
    }

    color ray_color(const ray& r, int depth, const hittable& world) const {
        hit_record rec;

        if(depth <= 0) {
            return color(0, 0, 0);
        }

        if(world.hit(r, interval(0.001, infinity), rec)) { // 0.001 to address the shadow acne. Result will be a bit lighter since the reflections has been optimized.
            ray scattered;
            color attenuation;

            if(rec.mat->scatter(r, rec, attenuation, scattered)) {
                return attenuation * ray_color(scattered, depth - 1, world);
            }

            return color(0, 0, 0);
        }

        vec3 unit_direction = unit_vector(r.direction());
        auto a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0); // lerp
    }
};

#endif