//#pragma once
//
//#include <iostream>
//
//namespace sparky { namespace math {
//
//    struct Vec3
//    {
//        float x, y, z;
//        Vec3();
//        Vec3(const float& x, const float& y, const float& z);
//
//        float getMagnitude() const;
//        Vec3& normalize();
//
//        Vec3& add(const Vec3& other);
//        Vec3& subtract(const Vec3& other);
//        Vec3& multiply(const Vec3& other);
//        Vec3& divide(const Vec3& other);
//        float dot(Vec3 other) const;
//
//        friend Vec3& operator+(Vec3 left, const Vec3& right);
//        friend Vec3& operator-(Vec3 left, const Vec3& right);
//        friend Vec3& operator*(Vec3 left, const Vec3& right);
//        friend Vec3& operator/(Vec3 left, const Vec3& right);
//
//        friend bool operator==(const Vec3& left, const Vec3& right);
//        friend bool operator!=(const Vec3& left, const Vec3& right);
//
//        Vec3& operator+=(const Vec3& other);
//        Vec3& operator-=(const Vec3& other);
//        Vec3& operator*=(const Vec3& other);
//        Vec3& operator/=(const Vec3& other);
//
//        Vec3 operator*(const float& scalar) const; // for scaling
//
//        //friend lets you use private stuff
//        //from a non-public class as if it is public
//        //this is just to stick with convention
//        friend std::ostream& operator<<(std::ostream& stream, const Vec3& vec);
//    };
//
//}}

#pragma once
#include <iostream>
#include <cmath>

class Vec3
{
public:
    float x, y, z;
    Vec3() : x(float(0)), y(float(0)), z(float(0)) {}
    Vec3(float xx) : x(xx), y(xx), z(xx) {}
    Vec3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
    Vec3& normalize()
    {
        float nor2 = length2();
        if (nor2 > 0) {
            float invNor = 1 / sqrt(nor2);
            x *= invNor, y *= invNor, z *= invNor;
        }
        return *this;
    }
    Vec3 operator * (const float &f) const { return Vec3(x * f, y * f, z * f); }
    Vec3 operator * (const Vec3 &v) const { return Vec3(x * v.x, y * v.y, z * v.z); }
    float dot(const Vec3 &v) const { return x * v.x + y * v.y + z * v.z; }
    Vec3 operator - (const Vec3 &v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator + (const Vec3 &v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3& operator += (const Vec3 &v) { x += v.x, y += v.y, z += v.z; return *this; }
    Vec3& operator *= (const Vec3 &v) { x *= v.x, y *= v.y, z *= v.z; return *this; }
    Vec3 operator - () const { return Vec3(-x, -y, -z); }
    float length2() const { return x * x + y * y + z * z; }
    float length() const { return sqrt(length2()); }
    friend std::ostream & operator << (std::ostream &os, const Vec3 &v)
    {
        os << "[" << v.x << " " << v.y << " " << v.z << "]";
        return os;
    }
};
