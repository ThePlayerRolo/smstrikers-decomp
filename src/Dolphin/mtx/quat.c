#include <dolphin.h>
#include <dolphin/mtx.h>
#include <math.h>

void PSQUATScale(const register Quaternion* q, register Quaternion* r, register f32 scale) {
    register f32 rxy, rzw;
    
    asm {
        psq_l rxy, 0(q), 0, 0
        psq_l rzw, 8(q), 0, 0
        ps_muls0 rxy, rxy, scale
        psq_st rxy, 0(r), 0, 0
        ps_muls0 rzw, rzw, scale
        psq_st rzw, 8(r), 0, 0
    }
}

f32 PSQUATDotProduct(const register Quaternion* p, const register Quaternion* q) 
{
    register f32 pxy, pzw, qxy, qzw, dp;

    asm {
        psq_l pxy, 0(p), 0, 0
        psq_l qxy, 0(q), 0, 0
        ps_mul dp, pxy, qxy
        psq_l pzw, 8(p), 0, 0
        psq_l qzw, 8(q), 0, 0
        ps_madd dp, pzw, qzw, dp
        ps_sum0 dp, dp, dp, dp
    }

    return dp;
}

void C_QUATSlerp(float t, const Quaternion* p, const Quaternion* q, Quaternion* r)
{
    // f32 dVar1;
    // f32 dVar2;
    f32 theta;
    f32 sin_th;
    f32 tq;
    f32 tp;
    f32 cos_th;
  
    tq = 1.0;
    cos_th = p->x * q->x + p->y * q->y + p->z * q->z + p->w * q->w;

    if (cos_th < 0.0f) 
    {
        cos_th = -cos_th;
        tq = -tq;
    }

    if (0.99999f < cos_th) 
    {
        tq = tq * t;
        tp = 1.0f - t;
    }
    else 
    {
        theta = acosf(cos_th);
        sin_th = sinf(theta);
        tp = sinf((1.0f - t) * theta) / sin_th;
        tq = tq * sinf(theta * t) / sin_th;
    }

  r->x = (tp * p->x) + (tq * q->x);
  r->y = (tp * p->y) + (tq * q->y);
  r->z = (tp * p->z) + (tq * q->z);
  r->w = (tp * p->w) + (tq * q->w);
  return;
}
