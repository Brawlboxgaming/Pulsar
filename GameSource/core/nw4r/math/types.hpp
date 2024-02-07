#ifndef _NW4R_MATH_TYPES_
#define _NW4R_MATH_TYPES_
#include <types.hpp>
#include <include/c_math.h>
#include <core/rvl/mtx/mtx.hpp>

namespace nw4r {
namespace math {

struct VEC2 {
    VEC2() {}
    VEC2(float x, float z) { this->x = x; this->z = z; }
    float x, z;
};

struct VEC3 : Vec {
    VEC3() {}
    VEC3(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }
    void Report(bool addNewLine, const char* prefixText = 0);
};

VEC2* VEC2Maximize(VEC2* dest, const VEC2* src1, const VEC2* src2); //80085580
VEC2* VEC2Minimize(VEC2* dest, const VEC2* src1, const VEC2* src2); //800855c0
VEC3* VEC3Maximize(VEC3* dest, const VEC3* src1, const VEC3* src2);
VEC3* VEC3Minimize(VEC3* dest, const VEC3* src1, const VEC3* src2);

struct QUAT {
    float x, y, z, w;
}; // total size 0x10

struct S16Vec3 { s16 x, y, z; };
typedef float Mat[3][4];
typedef Mat Mat34;
typedef float Mat44[4][4];
typedef float Mat43[4][3];



struct MTX33 {
    union {
        struct {
            float n00, n01, n02;
            float n10, n11, n12;
            float n20, n21, n22;
        };
        float element[3][3];
        float member[9];
    };
};

struct MTX34 {
    union {
        struct {
            float n00, n01, n02, n03;
            float n10, n11, n12, n13;
            float n20, n21, n22, n23;
        };
        float element[3][4];
        float member[12];
        Mat mtx;
    };
};

struct MTX44 {
    union {
        struct {
            float n00, n01, n02, n03;
            float n10, n11, n12, n13;
            float n20, n21, n22, n23;
            float n30, n31, n32, n33;
        };
        float element[4][4];
        float member[16];
        Mat44 mtx;
    };
};

struct MTX43 {
    union {
        struct {
            float n00, n01, n02;
            float n10, n11, n12;
            float n20, n21, n22;
            float n30, n31, n32;
        };
        float element[4][3];
        float member[12];
        Mat43 mtx;
    };
};

void MTX33Identity(MTX33* mtx);
void MTX34ToMTX33(MTX33* dest, const MTX34* source);
void MTX34Zero(MTX34* mtx);
void MTX34Add(MTX34* dest, const MTX34* sourceA, const MTX34* sourceB);
void MTX34Scale(MTX34* dest, const MTX34* sourceMatrix, const VEC3* sourceVector);
void MTX34Trans(MTX34* dest, const MTX34* sourceMatrix, const VEC3* sourceVector);
void MTX34RotAxisFIdx(MTX34* dest, const VEC3* vector, float fidx);
void MTX34RotXYZFIdx(MTX34* dest, float x, float y, float z);
void VEC3TransformNormal(VEC3* dest, const MTX34* sourceMatrix, const VEC3* sourceVector);
void MTX44Identity(MTX44* mtx);
void MTX44Copy(MTX44* dest, const MTX44* source);

}//namespace math
}//namespace nw4r

#endif
