#pragma once

#include "Vec3.hpp"
#include "maths_func.hpp"
#include <iostream>

namespace sparky { namespace math {
    
    struct Mat4
    {
        float elements[4 * 4];
        
        Mat4();
        Mat4(float diagonal);
        Mat4(float values[16]);
        
        static Mat4 identity();
        
        Mat4& multiply(const Mat4& other);
        friend Mat4 operator*(Mat4 left, const Mat4& right);
        Mat4& operator*=(const Mat4& other);
        
        static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
        static Mat4 perspective(float fov, float aspectRatio, float near, float far);
        
        static Mat4 translation(const Vec3& translation);
        static Mat4 rotation(float angle, const Vec3& axis);
        static Mat4 scale(const Vec3& scale);
        
        friend std::ostream& operator<<(std::ostream& stream, const Mat4& Mat);
        
    };
    
}}
