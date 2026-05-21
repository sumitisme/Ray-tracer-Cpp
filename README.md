# Ray-tracer-Cpp

## Prerequisites for the device:

The following are expected in the system:
* An instance of MinGW installed in the system (The msys64 installation recommended)
* CMake installed in the system (This project uses version 4.3.1)
* Windows (.bat files used here)

## To run the project (These steps are to run it in powershell):

* To build the project
  ```sh
  ./build.bat
  ```

* To run the project
  ```sh
  ./run.bat
  ```

## The very first output

![The very first output](/images/The%20very%20first%20output.png)

## The first ray traced sphere with surface normal mapped (background is a lerp from blue to white)

![Sphere with surface normals](/images/Sphere%20with%20surface%20normals.png)

## I increased the number of sampling (at the same resolution) and also kept a ground sphere

![Output after increasing sample size](/images/output%20after%20increasing%20sample%20size.png)

## Implemented a diffuse sphere and made the sphere a grayish color

![Diffuse material implemented](/images/Diffuse%20material%20implemented.png)

## Same sphere but more sampling

![Less noisy diffuse material implementation](/images/Resolution%20improved%20diffuse%20material%20implemented%20idk%20if%20it%20worked.png)

## Implemented True lambertian reflection so the shadows have more contrast (bluish because of the sky being tinted on the sphere)

![True Lambertian Reflection implemented](/images/True%20Lambertian%20reflection%20implemented.png)

## Implemented a different material class so I could assign materials to the sphere, kept some spheres as metals and the ground sphere as diffuse/Lambertian (also gamma corrected the output here)

![Metals, materials and more balls](/images/Metals%20and%20materials%20800%20samples.png)

## Resolution improved for the previous image (1600 x 900 as compared to 400 x 225)

![1600 x 900 image](/images/Resolution%20improved%20for%20the%20previous%20image.png)

## Fuzzy material implemented for metals (1600 x 900 image)

![fuzz implemented](/images/fuzz%20implemented%20and%20more%20random%20colors.png)

## Added dielectrics (Refractive index at 1.33)

![Added dielectrics](/images/Added%20dielectrics.png)

## Air bubble in water implemented (concepts of total internal reflection here)

![Air bubble](/images/Air%20bubble%20implemented.png)

## VFOV test with two spheres (vfov = 90)

![VFOV](/images/VFOV%20test%20with%20two%20spheres.png)

## Camera position and Camera direction changed (vfov = 90)

![Cam Lookat and Lookfrom](/images/Camera%20lookat%20and%20lookfrom.png)

## vfov changed to 20

![fov20](/images/fov20.png)

## Final render with defocus blur

![Final render](/images/final%20render%20with%20defocus%20blur.png)