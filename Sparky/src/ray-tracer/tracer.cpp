#include "tracer.hpp"

using namespace sparky;
using namespace math;

Vec3 trace(const Vec3& rayorig, const Vec3& raydir, const std::vector<Sphere> &spheres, const int &depth);
