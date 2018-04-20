#include "Sphere.hpp"

namespace sparky { namespace math {
    
    Sphere::Sphere(
             const Vec3 &c,
             const float &r,
             const Vec3 &sc,
             const float &refl,
             const float &transp,
             const Vec3 &ec) :
    center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
    transparency(transp), reflection(refl) {};

    bool Sphere::intersect(const Vec3 &rayorig, const Vec3 &raydir, float &t0, float &t1) const
    {
        Vec3 l = center - rayorig; // vector between the FOV origin and the center of the sphere
        float tca = l.dot(raydir); // project vec between FOV origin and center of sphere onto the direction of the "eye" ray
        if (tca < 0) return false; // this means the object is in front of the back of the FOV pyramid???
        float d2 = l.dot(l) - tca * tca; // d^2 = a^2 + b^2 -> finding squared distance between center of sphere and the end of tca (l projected onto the eye ray's direction)
        if (d2 > radius2) return false;
        float thc = sqrt(radius2 - d2); // distance betweeen radius and dSquared (distance between center and end of tca)
        t0 = tca - thc; // if ray goes THROUGH sphere need to bring it back onto the radius
        t1 = tca + thc; // if ray doesn't reach sphere but would intersect if it did
        
        return true;
    }
}}
