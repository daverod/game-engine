#pragma once
#include "Vec3.hpp"
#include "Sphere.hpp"
#include "maths_func.hpp"

namespace sparky { namespace math {
    struct RayTracer
    {
        static Vec3 trace(const Vec3& rayorig, const Vec3& raydir, const std::vector<Sphere> &spheres, const int &depth);
        
        static void render(const std::vector<Sphere> &spheres);
    };
}}
