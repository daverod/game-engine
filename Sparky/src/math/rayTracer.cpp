#include "rayTracer.hpp"
#include <vector>
#include <fstream>
#include <iostream>

namespace sparky { namespace math {
    
    Vec3 RayTracer::trace(const Vec3& rayOrig, const Vec3& rayDir, const std::vector<Sphere> &spheres, const int &depth) {
        float tnear = INFINITY;
        const Sphere* sphere = NULL;
        
        // ~FINDING INTERSECTION OF INPUT RAY WITH SPHERE~
        for(unsigned i = 0; i < spheres.size(); ++i){
            float t0 = INFINITY, t1 = INFINITY;
            if(spheres[i].intersect(rayOrig, rayDir, t0, t1)) {
                if(t0 < 0) t0 = t1; // this implies that the ray does not go through the sphere so we take t1, which needs to be extended to reach the sphere
                if(t0 < tnear) {
                    tnear = t0; // update the nearest z distance if a smaller one is encountered
                    sphere = &spheres[i]; // TODO: WTF?
                }
            }
        }
        // ~END FINDING INTERSECTION OF INPUT RAY WITH SPHERE~
        
        if (!sphere) {
            std::cout << "blarg" << std::endl;
            return Vec3(2, 2, 2); // return black if there's no intersection
        }
        
        Vec3 surfaceColor(0, 0, 0); // color of the ray/surfaceof the object intersected by the ray

        Vec3 pointOfIntersection = rayOrig + (rayDir * tnear); // translating the orig by the direction of the ray scaled by the distance from the "eye" the sphere is at
        
        Vec3 normalAtIntPoint = pointOfIntersection - sphere->center; // normal to intersection is just a radius
        
        normalAtIntPoint.normalize();
        
        float bias = 1e-4;
        
        // ~DEALING WITH IF VIEW IS INSIDE SPHERE
        bool inside = false;
        if (rayDir.dot(normalAtIntPoint) > 0){
            normalAtIntPoint = normalAtIntPoint * -1;
            inside = true;
        }
        // ~END DEALING WITH IF VIEW IS INSIDE SPHERE
        
        // FOR DIFFUSE OBJECTS
        for(unsigned i = 0; i < spheres.size(); i++) { // this checks if there are any objects in the way of the sphere on line 18;
            if(spheres[i].emissionColor.x > 0) {
                Vec3 transmission(1, 1, 1);
                
                // vector from the center of a sphere[i] to where the FOV ray intersects the main sphere
                Vec3 lightDirection = spheres[i].center - pointOfIntersection;
                
                lightDirection.normalize();
                
                 // checking if the vector emitted from v in the direction of sphere i intersects with any other spheres
                for(unsigned j = 0; j < spheres.size(); ++j) {
                    if(i != j) {
                        float t0, t1;
                        
                        // Interpret this as a point.
                        // END OF vector pointing out from the sphere where the FOV ray intersects that is normal to sphere and scaled by normal
                        Vec3 v = pointOfIntersection + normalAtIntPoint * bias;
                        
                        if(spheres[j].intersect(v, lightDirection, t0, t1)) {
                            transmission.x = 0;
                            transmission.y = 0;
                            transmission.z = 0;
                            break;
                        }
                        
                        float colorModifier = std::max(float(0), normalAtIntPoint.dot(lightDirection));
                        
                        surfaceColor += sphere->surfaceColor * transmission * colorModifier * spheres[i].emissionColor;
                        
                    }
                }
            }
        }
        
        return surfaceColor + sphere->emissionColor;
    };
    
    void RayTracer::render(const std::vector<Sphere> &spheres) {
        unsigned width = 640, height = 480;
        Vec3* image = new Vec3[width * height]; //array of pixels
        Vec3* pixel = image; // pointer to first pixel
        float invWidth = 1 / float(width);
        float invHeight = 1 / float(height);
        float fov = 30;
        float aspectratio = width / float(height);
        float angle = tan(M_PI * 0.5 * fov / 180.);
        
        for(unsigned y = 0; y < height; ++y) {
            for(unsigned x = 0; x < width; ++x, ++pixel) {
                float xx = (2 * ((x + 0.5) * invWidth) - 1) * angle * aspectratio; // TODO: WTF?
                float yy = (1 - 2 * ((y + 0.5) * invHeight)) * angle; // TODO: WTF?
                Vec3 raydir(xx, yy, -1); //zed going into the screen
                raydir.normalize();
                *pixel = trace(Vec3(0, 0, 0), raydir, spheres, 0); // starts from the origin and points in the direction of the pixel
            }
        }
        
        //     // Save result to a PPM image (keep these flags if you compile under Windows)
        std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
        ofs << "P6\n" << width << " " << height << "\n255\n";
        for (unsigned i = 0; i < width * height; ++i) {
            ofs << (unsigned char)(std::min(float(1), image[i].x) * 255) <<
            (unsigned char)(std::min(float(1), image[i].y) * 255) <<
            (unsigned char)(std::min(float(1), image[i].z) * 255);
        }
        ofs.close();
        delete [] image;
        
    }
}}
