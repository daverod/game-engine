#pragma once

#include <iostream>

namespace sparky { namespace math {
    
    struct Vec4
    {
        float x, y, z, w;
        Vec4();
        Vec4(const float& x, const float& y, const float& z, const float& w);
        
        Vec4& add(const Vec4& other);
        Vec4& subtract(const Vec4& other);
        Vec4& multiply(const Vec4& other);
        Vec4& divide(const Vec4& other);
        
        friend Vec4& operator+(Vec4 left, const Vec4& right);
        friend Vec4& operator-(Vec4 left, const Vec4& right);
        friend Vec4& operator*(Vec4 left, const Vec4& right);
        friend Vec4& operator/(Vec4 left, const Vec4& right);
        
        friend bool operator==(const Vec4& left, const Vec4& right);
        friend bool operator!=(const Vec4& left, const Vec4& right);
        
        Vec4& operator+=(const Vec4& other);
        Vec4& operator-=(const Vec4& other);
        Vec4& operator*=(const Vec4& other);
        Vec4& operator/=(const Vec4& other);
        
        //friend lets you use private stuff
        //from a non-public class as if it is public
        //this is just to stick with convention
        friend std::ostream& operator<<(std::ostream& stream, const Vec4& vec);
    };

}}
