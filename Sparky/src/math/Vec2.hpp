#pragma once

#include <iostream>

namespace sparky { namespace math {
    
    struct Vec2
    {
        float x, y;
        Vec2();
        Vec2(const float& x, const float& y);
        
        Vec2& add(const Vec2& other);
        Vec2& subtract(const Vec2& other);
        Vec2& multiply(const Vec2& other);
        Vec2& divide(const Vec2& other);
        
        friend Vec2& operator+(Vec2 left, const Vec2& right);
        friend Vec2& operator-(Vec2 left, const Vec2& right);
        friend Vec2& operator*(Vec2 left, const Vec2& right);
        friend Vec2& operator/(Vec2 left, const Vec2& right);
        
        friend bool operator==(const Vec2& left, const Vec2& right);
        friend bool operator!=(const Vec2& left, const Vec2& right);
        
        Vec2& operator+=(const Vec2& other);
        Vec2& operator-=(const Vec2& other);
        Vec2& operator*=(const Vec2& other);
        Vec2& operator/=(const Vec2& other);
        
        //friend lets you use private stuff
        //from a non-public class as if it is public
        //this is just to stick with convention
        friend std::ostream& operator<<(std::ostream& stream, const Vec2& vec);
    };

}}
