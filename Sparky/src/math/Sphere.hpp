#pragma once
#include "Vec3.hpp"
#include "maths_func.hpp"

namespace sparky { namespace math {
    
    class Sphere
    {
    public:
        Vec3 center;                           /// position of the sphere
        float radius, radius2;                  /// sphere radius and radius^2
        Vec3 surfaceColor, emissionColor;      /// surface color and emission (light)
        float transparency, reflection;         /// surface transparency and reflectivity
        Sphere(
               const Vec3 &c,
               const float &r,
               const Vec3 &sc,
               const float &refl = 0,
               const float &transp = 0,
               const Vec3 &ec = Vec3(0, 0, 0));
        bool intersect(const Vec3 &rayorig, const Vec3 &raydir, float &t0, float &t1) const;
    };
    
}}

