/*
[m1]  [m2]  [m3]  [m4]
[m5]  [m6]  [m7]  [m8]
[m9]  [m10] [m11] [m12]
[m13] [m14] [m15] [m16]
*/

#include "Vector4.h"
#include "Vector3.h"
#pragma once
namespace MathClasses
{
    struct Matrix4
    {
        Matrix4() {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10 = m11 = m12 = m13 = m14 = m15 = m16 = 0.0f;
        }

        Matrix4(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9, float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16) {
            m1 = _m1;
            m2 = _m2;
            m3 = _m3;
            m4 = _m4;
            m5 = _m5;
            m6 = _m6;
            m7 = _m7;
            m8 = _m8;
            m9 = _m9;
            m10 = _m10;
            m11 = _m11;
            m12 = _m12;
            m13 = _m13;
            m14 = _m14;
            m15 = _m15;
            m16 = _m16;
        }

        Matrix4(float floatarray[]) {
            m1 = floatarray[0];
            m2 = floatarray[1];
            m3 = floatarray[2];
            m4 = floatarray[3];
            m5 = floatarray[4];
            m6 = floatarray[5];
            m7 = floatarray[6];
            m8 = floatarray[7];
            m9 = floatarray[8];
            m10 = floatarray[9];
            m11 = floatarray[10];
            m12 = floatarray[11];
            m13 = floatarray[12];
            m14 = floatarray[13];
            m15 = floatarray[14];
            m16 = floatarray[15];
        }

        union {
            struct {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
            };

            float v[16];
            float mm[4][4];

            Vector4 axis[4];
        };

        static Matrix4 MakeIdentity() {
            Matrix4 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;
            identity.m4 = 0;
            identity.m5 = 0;
            identity.m6 = 1;
            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 0;
            identity.m10 = 0;
            identity.m11 = 1;
            identity.m12 = 0;
            identity.m13 = 0;
            identity.m14 = 0;
            identity.m15 = 0;
            identity.m16 = 1;
            return identity;
        }

        operator float* () { return v; }
        operator const float* () { return v; }


        /*
        [m1]  [m2]  [m3]  [m4]
        [m5]  [m6]  [m7]  [m8]
        [m9]  [m10] [m11] [m12]
        [m13] [m14] [m15] [m16]
        */

        Matrix4 Transposed() const {
            return Matrix4(m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15, m4, m8, m12, m16);
        }

        std::string ToString() const {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 16; i++) {
                str += ", " + std::to_string(v[i]);
            }
            return str;
        }

        float& operator [](int dim) {
            return v[dim];
        }

        const float& operator [](int dim) const {
            return v[dim];
        }

        Matrix4 operator *(Matrix4 rhs) const {
            Matrix4 result;

            for (size_t i = 0; i < 4; i++) {
                Vector4 row(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

                for (size_t j = 0; j < 4; j++) {
                    result.mm[j][i] = row.Dot(rhs.axis[j]);
                }
            }
            return result;
        }


        /*
        [m1]  [m2]  [m3]  [m4]
        [m5]  [m6]  [m7]  [m8]
        [m9]  [m10] [m11] [m12]
        [m13] [m14] [m15] [m16]
        */

        Vector4 operator *(Vector4 rhs) const {
            return Vector4(
                Vector4(m1, m5, m9, m13).Dot(rhs),
                Vector4(m2, m6, m10, m14).Dot(rhs),
                Vector4(m3, m7, m11, m15).Dot(rhs),
                Vector4(m4, m8, m12, m16).Dot(rhs)
            );
        }

        /*
        [m1]  [m2]  [m3]  [m4]
        [m5]  [m6]  [m7]  [m8]
        [m9]  [m10] [m11] [m12]
        [m13] [m14] [m15] [m16]
        */

        bool operator ==(Matrix4 rhs) const {
            Vector4 check1(m1, m5, m9, m13);
            Vector4 check2(m2, m6, m10, m14);
            Vector4 check3(m3, m7, m11, m15);
            Vector4 check4(m4, m8, m12, m16);

            if (check1 == Vector4(rhs.m1, rhs.m5, rhs.m9, rhs.m13) && check2 == Vector4(rhs.m2, rhs.m6, rhs.m10, m14) && check3 == Vector4(rhs.m3, rhs.m7, rhs.m11, rhs.m15) && check4 == Vector4(rhs.m4, rhs.m8, rhs.m12, rhs.m16))
                return true;
            return false;
        }

        bool operator !=(Matrix4 rhs) const {
            Vector4 check1(m1, m5, m9, m13);
            Vector4 check2(m2, m6, m10, m14);
            Vector4 check3(m3, m7, m11, m15);
            Vector4 check4(m4, m8, m12, m16);

            if (check1 == Vector4(rhs.m1, rhs.m5, rhs.m9, rhs.m13) && check2 == Vector4(rhs.m2, rhs.m6, rhs.m10, m14) && check3 == Vector4(rhs.m3, rhs.m7, rhs.m11, rhs.m15) && check4 == Vector4(rhs.m4, rhs.m8, rhs.m12, rhs.m16))
                return false;
            return true;
        }

        static Matrix4 MakeTranslation(float x, float y, float z) {
            return Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f, 0.0f,
                            0.0f, 0.0f, 1.0f, 0.0f,
                            x, y, z, 1);
        }

        static Matrix4 MakeTranslation(Vector4 other) {
            return MakeTranslation(other.x, other.y, other.z);
        }

        static Matrix4 MakeTranslation(math::Vector3 other) {
            return MakeTranslation(other.x, other.y, other.z);
        }

        static Matrix4 MakeScale(float xScale, float yScale, float zScale) {
            return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                0.0f, yScale, 0.0f, 0.0f,
                0.0f, 0.0f, zScale, 0.0f,
                0.0f, 0.0f, 0.0f, 1);
        }

        static Matrix4 MakeScale(float xScale, float yScale) {
            return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                0.0f, yScale, 0.0f, 0.0f,
                0.0f, 0.0f, 1.0f, 0.0f,
                0.0f, 0.0f, 0.0f, 1);
        }

        static Matrix4 MakeScale(math::Vector3 other) {
            return MakeScale(other.x, other.y, other.z);
        }

        static Matrix4 MakeRotateX(float a) {
            return Matrix4(1, 0, 0, 0,
                0, cosf(a), -sinf(a), 0,
                0, sinf(a), cosf(a), 0,
                0, 0, 0, 1);
        }

        static Matrix4 MakeRotateY(float a) {
            return Matrix4(cosf(a), 0, sinf(a), 0,
                0, 1, 0, 0,
                -sinf(a), 0, cosf(a), 0,
                0, 0, 0, 1);
        }

        static Matrix4 MakeRotateZ(float a) {
            return Matrix4(cosf(a), sinf(a), 0, 0,
                -sinf(a), cosf(a), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
        }

        static Matrix4 MakeEuler(float pitch, float yaw, float roll) {
            Matrix4 x = MakeRotateX(pitch);
            Matrix4 y = MakeRotateY(yaw);
            Matrix4 z = MakeRotateZ(roll);

            return (z * y * x);
        }

        static Matrix4 MakeEuler(math::Vector3 vector) {
            return MakeEuler(vector.x, vector.y, vector.z);
        }
	};
}