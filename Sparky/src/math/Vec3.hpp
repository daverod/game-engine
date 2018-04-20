#pragma once

#include <iostream>
#include <cmath>

namespace sparky { namespace math {

    struct Vec3
    {
        float x, y, z;
        Vec3();
        Vec3(const float& x, const float& y, const float& z);

        float getMagnitude() const;
        Vec3& normalize();

        Vec3& add(const Vec3& other);
        Vec3& subtract(const Vec3& other);
        Vec3& multiply(const Vec3& other);
        Vec3& divide(const Vec3& other);
        float dot(Vec3 other) const;

        friend Vec3& operator+(Vec3 left, const Vec3& right);
        friend Vec3& operator-(Vec3 left, const Vec3& right);
//        friend Vec3& operator*(Vec3 left, const Vec3& right);
        friend Vec3& operator/(Vec3 left, const Vec3& right);
        
        Vec3 operator*(const Vec3& other) const;

        friend bool operator==(const Vec3& left, const Vec3& right);
        friend bool operator!=(const Vec3& left, const Vec3& right);

        Vec3& operator+=(const Vec3& other);
        Vec3& operator-=(const Vec3& other);
        Vec3& operator*=(const Vec3& other);
        Vec3& operator/=(const Vec3& other);

        Vec3 operator*(const float& scalar) const; // for scaling
        
        float length2() const;
        float length() const;

        //friend lets you use private stuff
        //from a non-public class as if it is public
        //this is just to stick with convention
        friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);
    };

}}

