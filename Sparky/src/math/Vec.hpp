#pragma once

#include <iostream>

namespace sparky { namespace math {
    
    struct Vec
    {
        int dim;
        float* values;
        Vec(int dim);
        Vec(int dim, float* newVals);
        ~Vec();
        
        //copy constructor
        Vec(const Vec& newVec);
        
        Vec& add(const Vec& other);
        Vec& subtract(const Vec& other);
        Vec& multiply(const Vec& other);
        Vec& divide(const Vec& other);
        
        friend Vec& operator+(Vec left, const Vec& right);
        friend Vec& operator-(Vec left, const Vec& right);
        friend Vec& operator*(Vec left, const Vec& right);
        friend Vec& operator/(Vec left, const Vec& right);
        
        friend bool operator==(const Vec& left, const Vec& right);
        friend bool operator!=(const Vec& left, const Vec& right);
        
        Vec& operator+=(const Vec& other);
        Vec& operator-=(const Vec& other);
        Vec& operator*=(const Vec& other);
        Vec& operator/=(const Vec& other);
        
        //friend lets you use private stuff
        //from a non-public class as if it is public
        //this is just to stick with convention
        friend std::ostream& operator<<(std::ostream& stream, const Vec& vec);
    };
    
}}
