#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

namespace sparky { namespace math {
    inline float toRads(float degrees) {
        return degrees * (M_PI / 180.0f);
    };
}}

