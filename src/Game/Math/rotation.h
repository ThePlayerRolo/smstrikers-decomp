#ifndef _CROTATION
#define _CROTATION

#include "types.h"

typedef struct {
  float x;
  float y;
  float z;
} Vector3;

typedef union {
    float m[3][4];    // 3x4 matrix representation
    float a[12];      // flat array representation
} Matrix3x4; 

typedef struct {
  float x;
  float y;
  float z;
  float w;
} Quaternion;

#endif
