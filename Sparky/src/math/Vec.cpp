#include "Vec.hpp"

namespace sparky { namespace math {
    
    Vec::Vec(int size)
    {
        dim = size;
    }
    
    Vec::Vec(int size, float* newVals)
    {
        dim = size;
        values = newVals;
    }
    
    Vec::~Vec()
    {
        delete[] values;
        values = nullptr;
    }
    
    // copy constructor
    Vec::Vec(const Vec& newVec)
    {
        dim = newVec.dim;
        float* temp = new float[dim];
        for(int i = 0; i < dim; i++)
        {
            temp[i] = newVec.values[i];
        }
        values = temp;
    }
    
    Vec& Vec::add(const Vec& other)
    {
        for(int i = 0; i < dim; i++)
        {
            values[i] += other.values[i];
        }
        return *this;
    }
    
    // copy constructor is called here for first param
    Vec& operator+(Vec left, const Vec& right)
    {
        return left.add(right);
    }
    
    std::ostream& operator<<(std::ostream& stream, const Vec& vec)
    {
        stream << "Vec: <";
        for(int i = 0; i < vec.dim - 1; i++)
        {
            stream << vec.values[i] << ", ";
        }
        stream << vec.values[vec.dim - 1];
        stream << ">";
        return stream;
    }
}}
