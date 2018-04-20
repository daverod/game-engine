#include "Mat4.hpp"

namespace sparky { namespace math {
    
    Mat4::Mat4()
    {
        for(int i = 0; i < 4 * 4; i++)
            elements[i] = 0.0f;
    }
    
    Mat4::Mat4(float diagonal)
    {
        for(int i = 0; i < 4 * 4; i++)
            elements[i] = 0.0f;
        
        elements[0 + 0 * 4] = diagonal;
        elements[1 + 1 * 4] = diagonal;
        elements[2 + 2 * 4] = diagonal;
        elements[3 + 3 * 4] = diagonal;
    }
    
    Mat4::Mat4(float values[4 * 4])
    {
        for(int i = 0; i < 4 * 4; i++) { elements[i] = values[i]; }
    }
    
    Mat4 Mat4::identity()
    {
        return Mat4(1.0f);
    }
    
    Mat4& Mat4::multiply(const Mat4& other)
    {
        float result[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::cout << *this << std::endl;
        std::cout << other << std::endl;
        for(int row = 0; row < 4; row++) {
            for(int col = 0; col < 4; col++) {
                float sum = 0;
                int i = 0;
                for(int i = 0; i < 4; i++) {
                    sum += elements[row + 4 * i] * other.elements[4 * col + i];
                }
                result[row + col * 4] = sum;
            }
        }
        // some example cases because I'm dumb
        
        // row 0, col 0
        // result[0] = this->elements[0]  * other.elements[0] +
        //             this->elements[4]  * other.elements[1] +
        //             this->elements[8]  * other.elements[2] +
        //             this->elements[12] * other.elements[3];
        //
        // row 0, col 1
        // result[4] = this->elements[0]  * other.elements[4] +
        //             this->elements[4]  * other.elements[5] +
        //             this->elements[8]  * other.elements[6] +
        //             this->elements[12] * other.elements[7];
        //
        // row 2, col 2
        // result[10] = this->elements[2]  * other.elements[8] +
        //              this->elements[6]  * other.elements[9] +
        //              this->elements[10] * other.elements[10] +
        //              this->elements[14] * other.elements[11];
        
        for(int row = 0; row < 4; row++) {
            for(int col = 0; col < 4; col++) {
                this->elements[row + col * 4] = result[row + col * 4];
            }
        }
        return *this;
    }
    
    // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15. 16]
    // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    
    // ~COLUMN MAJOR~
    
    //[1, 5, 9,  13
    // 2, 6, 10, 14
    // 3, 7, 11, 15
    // 4, 8, 12, 16]

    std::ostream& operator<<(std::ostream& stream, const Mat4& mat)
    {
        stream << "Mat4: \n[";
        for (int i = 0; i < 4; i++)
        {
            if(i != 0) {
                stream << " ";
            };
            for (int j = 0; j < 4; j++) {
                stream
                    << mat.elements[i + j * 4] << ", ";
            }
            if(i != 3) {
                stream << "\n";
            };
        }
        stream << "]";
        return stream;
    }
    
    Mat4 operator*(Mat4 left, const Mat4& right)
    {
        return left.multiply(right);
    }
    
    Mat4& Mat4::operator*=(const Mat4& other)
    {
        return multiply(other);
    }
    
    Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
    {
        Mat4 result(1.0f);
        
        result.elements[0 + 0 * 4] = 2 / (right - left);
        result.elements[1 + 1 * 4] = 2 / (top - bottom);
        result.elements[2 + 2 * 4] = 2 / (near - far);
        
        result.elements[0 + 3 * 4] = (left + right) / (left - right);
        result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
        result.elements[2 + 3 * 4] = (far + near) / (far - near);
        
        return result;
    }
    
    Mat4 Mat4::perspective(float fov, float aspectRatio, float near, float far)
    {
        Mat4 result(1.0f);
        
        float q = 1.0f / tan(toRads(0.5f * fov));
        float a = q / aspectRatio;
        float b = (near + far) / (near - far);
        float c = (2.0f * near * far) / (near - far);
        
        result.elements[0 + 0 * 4] = a;
        result.elements[1 + 1 * 4] = q;
        result.elements[2 + 2 * 4] = b;
        result.elements[3 + 2 * 4] = -1.0f;
        result.elements[2 + 3 * 4] = c;
        result.elements[3 + 3 * 4] = 0;
        
        return result;
    }
    
    Mat4 Mat4::translation(const Vec3& translation)
    {
        Mat4 result(1.0f);
        
        result.elements[0 + 3 * 4] = translation.x;
        result.elements[1 + 3 * 4] = translation.y;
        result.elements[2 + 3 * 4] = translation.z;
        
        return result;
    }
    
    Mat4 Mat4::rotation(float angle, const Vec3& axis)
    {
        Mat4 result(1.0f);
        
        float r = toRads(angle);
        float c = cos(r);
        float s = sin(r);
        float omc = 1.0f - c;
        
        float x = axis.x;
        float y = axis.y;
        float z = axis.z;
        
        
        result.elements[0 + 0 * 4] = x * omc + c;
        result.elements[0 + 1 * 4] = (x * y) * omc + (z * s);
        result.elements[0 + 2 * 4] = (x * z) * omc - (y * s);
        
        result.elements[1 + 0 * 4] = (x * y) * omc - (z * s);
        result.elements[1 + 1 * 4] = y * omc + c;
        result.elements[1 + 2 * 4] = (y * z) * omc + (x * s);
        
        result.elements[2 + 0 * 4] = (x * z) * omc + (y * s);
        result.elements[2 + 1 * 4] = (y * z) * omc - (x * s);
        result.elements[2 + 2 * 4] = z * omc + c;
        
        return result;
    }
    
    Mat4 Mat4::scale(const Vec3& scale)
    {
        Mat4 result(1.0f);
        
        result.elements[0 + 0 * 4] = scale.x;
        result.elements[1 + 1 * 4] = scale.y;
        result.elements[2 + 2 * 4] = scale.z;
        
        return result;
    }
}}
