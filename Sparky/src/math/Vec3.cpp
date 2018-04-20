//#include "Vec3.hpp"
//#include "maths_func.hpp"
//
//namespace sparky { namespace math {
//    
//    Vec3::Vec3()
//    {
//        x = 0.0f;
//        y = 0.0f;
//        z = 0.0f;
//    }
//    
//    Vec3::Vec3(const float& x, const float& y, const float& z)
//    {
//        this->x = x;
//        this->y = y;
//        this->z = z;
//    }
//    
//    float Vec3::getMagnitude() const
//    {
//        return sqrt((x * x) + (y * y) + (z * z));
//    }
//    
//    Vec3& Vec3::normalize()
//    {
//        float magnitude = getMagnitude();
//        
//        if (magnitude * magnitude > 0) {
//            float inverse = 1 / magnitude;
//            x *= inverse;
//            y *= inverse;
//            z *= inverse;
//        }
//        
//        return *this;
//    }
//    
//    Vec3& Vec3::add(const Vec3& other)
//    {
//        x += other.x;
//        y += other.y;
//        z += other.z;
//        
//        return *this;
//    }
//    
//    Vec3& Vec3::subtract(const Vec3& other)
//    {
//        x -= other.x;
//        y -= other.y;
//        z -= other.z;
//        
//        return *this;
//    }
//    
//    Vec3& Vec3::multiply(const Vec3& other)
//    {
//        x *= other.x;
//        y *= other.y;
//        z *= other.z;
//        
//        return *this;
//    }
//    
//    Vec3& Vec3::divide(const Vec3& other)
//    {
//        x /= other.x;
//        y /= other.y;
//        z /= other.z;
//        
//        return *this;
//    }
//    
//    float Vec3::dot(Vec3 other) const
//    {
//        return ((x * other.x) + (y * other.y) + (z * other.z));
//    }
//    
//    Vec3& operator+(Vec3 left, const Vec3& right)
//    {
//        return left.add(right);
//    }
//    
//    Vec3& operator-(Vec3 left, const Vec3& right)
//    {
//        return left.subtract(right);
//    }
//    
//    Vec3& operator*(Vec3 left, const Vec3& right)
//    {
//        return left.multiply(right);
//    }
//    
//    Vec3& operator/(Vec3 left, const Vec3& right)
//    {
//        return left.divide(right);
//    }
//    
//    Vec3& Vec3::operator+=(const Vec3& other)
//    {
//        return add(other);
//    }
//    
//    Vec3& Vec3::operator-=(const Vec3& other)
//    {
//        return subtract(other);
//    }
//    
//    Vec3& Vec3::operator*=(const Vec3& other)
//    {
//        return multiply(other);
//    }
//    
//    Vec3& Vec3::operator/=(const Vec3& other)
//    {
//        return divide(other);
//    }
//    
//    bool operator==(const Vec3& left, const Vec3& right)
//    {
//        return ((left.x == right.x) && (left.y == right.y) && (left.z == right.z));
//    }
//    
//    bool operator!=(const Vec3& left, const Vec3& right)
//    {
//        return !(left == right);
//    }
//    
//    Vec3 Vec3::operator*(const float& scalar) const
//    {
//        return Vec3(x * scalar, y * scalar, z * scalar);
//    }
//    
//    std::ostream& operator<<(std::ostream& stream, const Vec3& vec)
//    {
//        stream << "Vec3: <" << vec.x << ", " << vec.y << ", " << vec.z << ">";
//        return stream;
//    }
//    
//}}
//
