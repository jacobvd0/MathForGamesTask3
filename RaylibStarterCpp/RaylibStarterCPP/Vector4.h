#pragma once

#include <string>

namespace MathClasses
{
    struct Vector4
    {
        Vector4() : w{ 0 }, x { 0 }, y{ 0 }, z{ 0 }
        {
        }

        Vector4(float x, float y, float z, float w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        union {
            struct { float x, y, z, w; };
            //struct { float r, g, b; };
            float data[4];
        };

        // [] Operator
        float& operator [](int dim) {
            return data[dim];
        }


        operator float* () { return data; }

        operator const float* () const { return data; };

        // + Operator
        Vector4 operator +(const Vector4& rhs) const {
            Vector4 sum;
            sum.w = w + rhs.w;
            sum.x = x + rhs.x;
            sum.y = y + rhs.y;
            sum.z = z + rhs.z;

            return sum;
        }

        // - Operator
        Vector4 operator -(const Vector4& rhs) const {
            Vector4 sum;

            sum.w = w - rhs.w;
            sum.x = x - rhs.x;
            sum.y = y - rhs.y;
            sum.z = z - rhs.z;

            return sum;
        }

        // * Operator
        Vector4 operator *(const Vector4& rhs) const {
            Vector4 sum;

            sum.w = w * rhs.w;
            sum.x = x * rhs.x;
            sum.y = y * rhs.y;
            sum.z = z * rhs.z;

            return sum;
        }

        // * Operator
        Vector4 operator *(const float multiplier) const {
            Vector4 sum;

            sum.w = w * multiplier;
            sum.x = x * multiplier;
            sum.y = y * multiplier;
            sum.z = z * multiplier;

            return sum;
        }

        // / Operator
        Vector4 operator /(const float division) const {
            Vector4 sum;

            sum.w = w / division;
            sum.x = x / division;
            sum.y = y / division;
            sum.z = z / division;

            return sum;
        }

        // == Operator
        bool operator == (const Vector4& rhs) const {
            float wDist = w - rhs.w;
            float xDist = x - rhs.x;
            float yDist = y - rhs.y;
            float zDist = z - rhs.z;

            const float THRESHOLD = 0.00001f;

            return xDist < THRESHOLD && yDist < THRESHOLD && zDist < THRESHOLD && wDist < THRESHOLD;
        }

        // != Operator
        bool operator != (const Vector4& rhs) const {
            return !(*this == rhs);
        }

        // Returns the Vector3 as a string (x, y ,z)
        std::string ToString() const
        {
            return std::to_string(w) + ", " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
        }

        // Calculates the magnitude
        float Magnitude() const {
            return sqrtf(w * w + x * x + y * y + z * z);
        }

        // Calculates the distance between 2 points
        float Distance(const Vector4& other) const {
            return (*this - other).Magnitude();
        }

        // Normalise
        void Normalise() {
            float m = Magnitude();

            if (m != 0) {
                if (w != 0)
                    w /= m;

                if (x != 0)
                    x /= m;

                if (y != 0)
                    y /= m;

                if (z != 0)
                    z /= m;
            }
            else {
                w = x = y = z = 0;
            }

            
        }

        // Normalised
        Vector4 Normalised() const {
            Vector4 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector4& other)
        {
            return w * other.w + x * other.x + y * other.y + z * other.z;
        }

        Vector4 Vector4::Cross(const Vector4& other) {
            /*return Vector4(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x,
                0);*/

            return Vector4(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x,
                0);
        }
    };


}