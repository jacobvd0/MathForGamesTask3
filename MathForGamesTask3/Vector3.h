#pragma once

#include <string>
#include <iostream>

namespace MathClasses
{
    struct Vector3
    {

        Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
        {
        }

        Vector3(float x,float y,float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;

            //data[0] = x;
            //data[1] = y;
            //data[2] = z;
        }

        union {
            struct { float x, y, z; };
            //struct { float r, g, b; };
            float data[3];
        };
        
        // [] Operator
        float& operator [](int dim) {
            return data[dim];
        }

        
        operator float* () { return data; }
        
        operator const float* () const { return data; };

        // + Operator
        Vector3 operator +(const Vector3& rhs) const {
            Vector3 sum;
            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;

            return sum;
        }

        // - Operator
        Vector3 operator -(const Vector3& rhs) const {
            Vector3 sum;

            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;

            return sum;
        }
        
        // * Operator
        Vector3 operator *(const Vector3& rhs) const {
            Vector3 sum;

            sum.x = x * rhs.x;
            sum.y = y * rhs.y;
            sum.z = z * rhs.z;

            return sum;
        }

        // * Operator
        Vector3 operator *(const float multiplier) const {
            Vector3 sum;

            sum.x = x * multiplier;
            sum.y = y * multiplier;
            sum.z = z * multiplier;

            return sum;
        }

        // / Operator
        Vector3 operator /(const float division) const {
            Vector3 sum;

            sum.x = x / division;
            sum.y = y / division;
            sum.z = z / division;

            return sum;
        }

        // == Operator
        bool operator == (const Vector3& rhs) const {
            float xDist = x - rhs.x;
            float yDist = y - rhs.y;
            float zDist = z - rhs.z;

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD;
        }

        // != Operator
        bool operator != (const Vector3& rhs) const {
            return !(*this == rhs);
        }

        // Returns the Vector3 as a string (x, y ,z)
        std::string ToString() const
        {
            return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        // Calculates the magnitude
        float Magnitude() const {
            return sqrtf(x * x + y * y + z * z);
        }

        // Calculates the distance between 2 points
        float Distance(const Vector3& other) const {
            return (*this - other).Magnitude();
        }

        // Normalise
        void Normalise() {
            float m = Magnitude();
            if (m != 0) {
                if (x != 0)
                    x /= m;

                if (y != 0)
                    y /= m;

                if (z != 0)
                    z /= m;
            }
            else {
                x = y = z = 0;
            }
            
        }

        // Normalised
        Vector3 Normalised() const {
            Vector3 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector3& other)
        {
            return x * other.x + y * other.y + z * other.z;
        }

        Vector3 Vector3::Cross(const Vector3& other) {
            return Vector3(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
        }
	};

    
}