#include "Game/rotation.h"

#include <math.h>

/*
 * --INFO--

  Game/rotation.c:
  .text       start:0x80223658 end:0x80223A4C
  .sdata2     start:0x80377720 end:0x80377730

  dDQfromW = .text:0x80223658; // type:function size:0x78 scope:global align:4
  dQfromR = .text:0x802236D0; // type:function size:0x224 scope:global align:4
  dRfromQ = .text:0x802238F4; // type:function size:0xA8 scope:global align:4
  dQMultiply0 = .text:0x8022399C; // type:function size:0x74 scope:global align:4
  dRSetIdentity = .text:0x80223A10; // type:function size:0x3C scope:global align:4

 */

/**
 * Calculates the derivative of a quaternion from an angular velocity vector
 * 
 * @param dq_out    Output quaternion derivative [x, y, z, w]
 * @param w_in      Input angular velocity vector [wx, wy, wz]
 * @param q_in      Input current quaternion [x, y, z, w]
 * 
 * The formula is: dq/dt = 0.5 * ω ⊗ q
 * where ω is the angular velocity vector and q is the current quaternion
 */
void dDQfromW(float *dq_out, float *w_in, float *q_in)
{
  // Extract angular velocity components
  float wx = w_in[0];
  float wy = w_in[1];
  float wz = w_in[2];

  // Extract quaternion components
  float fVar5 = q_in[1];
  float fVar3 = q_in[2];
  float fVar4 = q_in[3];
  float fVar6 = q_in[0];

  float half = 0.5f;

  dq_out[0] = half * -(wz * fVar4 - (-wx * fVar5 - wy * fVar3));
  dq_out[1] = half * -(wz * fVar3 - (wx * fVar6 + wy * fVar4));
  dq_out[2] = half * (wz * fVar5 + -wx * fVar4 + wy * fVar6);
  dq_out[3] = half * (wz * fVar6 + (wx * fVar3 - wy * fVar5));
}

/**
 * Converts a rotation matrix to a quaternion
 * 
 * @param q_out    Output quaternion [x, y, z, w]
 * @param m_in     Input 3x3 rotation matrix (stored as 12 floats)
 * 
 * The matrix is expected to be in column-major order:
 * [m00 m10 m20]
 * [m01 m11 m21]
 * [m02 m12 m22]
 */
void dQfromR(float *q_out, float *m_in)
{
    float trace = m_in[0] + m_in[5] + m_in[10];  // m00 + m11 + m22
    float s;
    
    if (trace > 0.0f) {
        // Case 1: Trace is positive
        s = 0.5f / sqrtf(trace + 1.0f);
        q_out[3] = 0.25f / s;  // w
        q_out[0] = (m_in[6] - m_in[9]) * s;  // x
        q_out[1] = (m_in[8] - m_in[2]) * s;  // y
        q_out[2] = (m_in[1] - m_in[4]) * s;  // z
    } else {
        // Case 2: Trace is negative or zero
        if (m_in[0] > m_in[5] && m_in[0] > m_in[10]) {
            // m00 is the largest diagonal
            s = 0.5f / sqrtf(1.0f + m_in[0] - m_in[5] - m_in[10]);
            q_out[0] = 0.25f / s;  // x
            q_out[1] = (m_in[1] + m_in[4]) * s;  // y
            q_out[2] = (m_in[8] + m_in[2]) * s;  // z
            q_out[3] = (m_in[6] - m_in[9]) * s;  // w
        } else if (m_in[5] > m_in[10]) {
            // m11 is the largest diagonal
            s = 0.5f / sqrtf(1.0f + m_in[5] - m_in[0] - m_in[10]);
            q_out[0] = (m_in[1] + m_in[4]) * s;  // x
            q_out[1] = 0.25f / s;  // y
            q_out[2] = (m_in[6] + m_in[9]) * s;  // z
            q_out[3] = (m_in[8] - m_in[2]) * s;  // w
        } else {
            // m22 is the largest diagonal
            s = 0.5f / sqrtf(1.0f + m_in[10] - m_in[0] - m_in[5]);
            q_out[0] = (m_in[8] + m_in[2]) * s;  // x
            q_out[1] = (m_in[6] + m_in[9]) * s;  // y
            q_out[2] = 0.25f / s;  // z
            q_out[3] = (m_in[1] - m_in[4]) * s;  // w
        }
    }
}

// void dQfromR(float *q_out, float *m_in)
// {
//   float fVar1;
//   float fVar2;
//   float fVar3;
//   float fVar4;
//   float fVar5;
//   float fVar6;
//   float fVar7;
//   int unaff_r2;
//   double dVar8;

//   float fVar54b8 = 1.0f;
  
//   fVar1 = m_in[0];
//   fVar2 = m_in[5];
//   fVar3 = m_in[10];
//   fVar4 = fVar3 + fVar1 + fVar2;
//   if (fVar4 < *(float *)(unaff_r2 + -0x54bc)) {
//     if (fVar2 <= fVar1) {
//       if (fVar3 <= fVar1) {
//         // dVar8 = (double)nlMath::nlSqrt(fVar54b8 + (fVar1 - (fVar2 + fVar3))),1);
//         dVar8 = sqrtf(fVar54b8 + (fVar1 - (fVar2 + fVar3)));

//         fVar2 = m_in[1];
//         fVar3 = m_in[4];
//         fVar4 = m_in[8];
//         fVar5 = m_in[2];
//         fVar6 = m_in[9];
//         fVar7 = m_in[6];
//         fVar1 = (float)((double)*(float *)(unaff_r2 + -0x54c0) *
//                        (double)(float)((double)*(float *)(unaff_r2 + -0x54b8) / dVar8));
//         q_out[1] = (float)((double)*(float *)(unaff_r2 + -0x54c0) * dVar8);
//         q_out[2] = fVar1 * (fVar2 + fVar3);
//         q_out[3] = fVar1 * (fVar4 + fVar5);
//         q_out[0] = fVar1 * (fVar6 - fVar7);
//         return;
//       }
//     }
//     else if (fVar3 <= fVar2) {
//       dVar8 = (double)nlMath::nlSqrt((double)(*(float *)(unaff_r2 + -0x54b8) + (fVar2 - (fVar3 + fVar1))), 1);
//       fVar2 = m_in[6];
//       fVar3 = m_in[9];
//       fVar4 = m_in[1];
//       fVar5 = m_in[4];
//       fVar6 = m_in[2];
//       fVar7 = m_in[8];
//       fVar1 = (float)((double)*(float *)(unaff_r2 + -0x54c0) *
//                      (double)(float)((double)*(float *)(unaff_r2 + -0x54b8) / dVar8));
//       q_out[2] = (float)((double)*(float *)(unaff_r2 + -0x54c0) * dVar8);
//       q_out[3] = fVar1 * (fVar2 + fVar3);
//       q_out[1] = fVar1 * (fVar4 + fVar5);
//       q_out[0] = fVar1 * (fVar6 - fVar7);
//       return;
//     }
//     dVar8 = (double)nlMath::nlSqrt((double)(*(float *)(unaff_r2 + -0x54b8) +
//                                            (fVar3 - (fVar1 + fVar2))),1);
//     fVar2 = m_in[8];
//     fVar3 = m_in[2];
//     fVar4 = m_in[6];
//     fVar5 = m_in[9];
//     fVar6 = m_in[4];
//     fVar7 = m_in[1];
//     fVar1 = (float)((double)*(float *)(unaff_r2 + -0x54c0) *
//                    (double)(float)((double)*(float *)(unaff_r2 + -0x54b8) / dVar8));
//     q_out[3] = (float)((double)*(float *)(unaff_r2 + -0x54c0) * dVar8);
//     q_out[1] = fVar1 * (fVar2 + fVar3);
//     q_out[2] = fVar1 * (fVar4 + fVar5);
//     q_out[0] = fVar1 * (fVar6 - fVar7);
//   }
//   else {
//     dVar8 = (double)nlMath::nlSqrt((double)(*(float *)(unaff_r2 + -0x54b8) + fVar4),1);
//     fVar2 = m_in[9];
//     fVar3 = m_in[6];
//     fVar4 = m_in[2];
//     fVar5 = m_in[8];
//     fVar6 = m_in[4];
//     fVar7 = m_in[1];
//     fVar1 = (float)((double)*(float *)(unaff_r2 + -0x54c0) *
//                    (double)(float)((double)*(float *)(unaff_r2 + -0x54b8) / dVar8));
//     q_out[0] = (float)((double)*(float *)(unaff_r2 + -0x54c0) * dVar8);
//     q_out[1] = fVar1 * (fVar2 - fVar3);
//     q_out[2] = fVar1 * (fVar4 - fVar5);
//     q_out[3] = fVar1 * (fVar6 - fVar7);
//   }
//   return;
// }

/*
Converts a quaternion to a rotation matrix
*/
void dRfromQ(float *m_out, float *q_in)
{
  const float fVar1 = 2.0f;
  float fVar4 = q_in[0];    // x
  float fVar5 = q_in[1];  // w
  float fVar2 = q_in[2];  // y
  float fVar3 = q_in[3];  // z
  const float fVar6 = 1.0f;
  
  // Calculate squared terms
  float fVar8 = fVar1 * fVar2 * fVar2;  // 2y²
  float fVar7 = fVar1 * fVar3 * fVar3;  // 2z²
  
  // First row
  m_out[0] = (fVar6 - fVar8) - fVar7;  // 1 - 2y² - 2z²
  m_out[1] = fVar1 * (fVar5 * fVar2 - fVar4 * fVar3);  // 2(wy - xz)
  m_out[2] = fVar1 * (fVar5 * fVar3 + fVar4 * fVar2);  // 2(wz + xy)
  
  // Second row
  m_out[4] = fVar1 * (fVar5 * fVar2 + fVar4 * fVar3);  // 2(wy + xz)
  m_out[5] = fVar6 - fVar7;  // 1 - 2z²
  m_out[6] = fVar1 * (fVar2 * fVar3 - fVar4 * fVar5);  // 2(yz - wx)
  
  // Third row
  m_out[8] = fVar1 * (fVar5 * fVar3 - fVar4 * fVar2);  // 2(wz - xy)
  m_out[9] = fVar1 * (fVar2 * fVar3 + fVar4 * fVar5);  // 2(yz + wx)
  m_out[10] = fVar6 - fVar8;  // 1 - 2y²
}

// void __dRfromQ(float *m_out, float *q_in) {
//     float w = q_in[0];
//     float x = q_in[1];
//     float y = q_in[2];
//     float z = q_in[3];

//     float ww = w * w;
//     float xx = x * x;
//     float yy = y * y;
//     float zz = z * z;
//     float wx = w * x;
//     float wy = w * y;
//     float wz = w * z;
//     float xy = x * y;
//     float xz = x * z;
//     float yz = y * z;

//     m_out[0] = 1.0f - 2.0f * (yy + zz);
//     m_out[1] = 2.0f * (xy - wz);
//     m_out[2] = 2.0f * (xz + wy);

//     m_out[3] = 2.0f * (xy + wz);
//     m_out[4] = 1.0f - 2.0f * (xx + zz);
//     m_out[5] = 2.0f * (yz - wx);

//     m_out[6] = 2.0f * (xz - wy);
//     m_out[7] = 2.0f * (yz + wx);
//     m_out[8] = 1.0f - 2.0f * (xx + yy);
// }

/*
Multiplies two quaternions
*/
void dQMultiply0(float *q_out,float *q1_in,float *q2_in)
{
  float w1 = q1_in[0];
  float x1 = q1_in[1];
  float y1 = q1_in[2];
  float z1 = q1_in[3];

  float w2 = q2_in[0];
  float x2 = q2_in[1];
  float y2 = q2_in[2];
  float z2 = q2_in[3];

  q_out[0] = -((z1 * z2) - -(y1 * y2 - (w1 * w2 - x1 * x2)));
  q_out[1] = -((z1 * y2) -  (y1 * z2 + (w1 * x2 + x1 * w2)));
  q_out[2] = -((x1 * z2) -  (z1 * x2 + (w1 * y2 + y1 * w2)));
  q_out[3] = -((y1 * x2) -  (x1 * y2 + (w1 * z2 + z1 * w2)));
}


// void dQMultiply0(float *q_out,float *q1_in,float *q2_in)
// {
//     asm {
// 		lfs f5,4(r4)
// 		lfs f9,8(r4)
// 		lfs f11,0xc(r4)
//     }

//     float x1 = q1_in[1];
//     float x2 = q2_in[1];
//     float w2 = q2_in[0];
//     float w1 = q1_in[0];   
//     float y1 = q1_in[2];
//     float z1 = q1_in[3]; // f11
//     float y2 = q2_in[2]; // f8
//     float z2 = q2_in[3];
    
//     // q_out[0] = -((z1 * z2) - -((y1 * y2) - ((w1 * w2) - (x1 * x2))));
//     q_out[0] = -((z1 * z2) + ((y1 * y2) - ((w1 * w2) - (x1 * x2))));
//     q_out[1] = -((z1 * y2) -  ((y1 * z2) + ((w1 * x2) + (x1 * w2))));
//     q_out[2] = -((x1 * z2) -  ((z1 * x2) + ((w1 * y2) + (y1 * w2))));
//     q_out[3] = -((y1 * x2) -  ((x1 * y2) + ((w1 * z2) + (z1 * w2))));
// }

/*
Sets a rotation matrix to identity
*/
void dRSetIdentity(float *mat)
{
    mat[0] = 1.0f;
    mat[1] = 0.0f;
    mat[2] = 0.0f;
    mat[3] = 0.0f;

    mat[4] = 0.0f;
    mat[5] = 1.0f;
    mat[6] = 0.0f;
    mat[7] = 0.0f;

    mat[8] = 0.0f;
    mat[9] = 0.0f;
    mat[10] = 1.0f;
    mat[11] = 0.0f;
}
