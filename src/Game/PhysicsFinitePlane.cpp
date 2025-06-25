
#include "PhysicsFinitePlane.h"
#include "ode/ext/dFinitePlane.h"

/**
 * Offset/Address/Size: 0x0 | 0x801FFAE4 | size: 0x218
 */
PhysicsFinitePlane::PhysicsFinitePlane(CollisionSpace* collision_space, nlVector3& pos, nlVector3& v1, nlVector3& v2, bool arg5, float arg8)
    : PhysicsObject(NULL)
{
    m_param = arg8;
    m_vec4.x = 0.f; // unk2C
    m_vec4.y = 0.f; // unk30
    m_vec4.z = 0.f; // unk34
    m_vec4.w = 0.f; // unk38

    m_vec4.y = nlSqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z, true);
    m_vec4.w = nlSqrt(v2.x * v2.x + v2.y * v2.y + v2.z * v2.z, true);
    m_vec4.x = -m_vec4.y;
    m_vec4.z = -m_vec4.w;

    float l = 1.f / m_vec4.y;
    v1.x = l * v1.x;
    v1.y = l * v1.y;
    v1.z = l * v1.z;

    float l2 = 1.f / m_vec4.w;
    v2.x = l2 * v2.x;
    v2.y = l2 * v2.y;
    v2.z = l2 * v2.z;

    float temp_f7 = v1.x;
    float temp_f5 = v1.y;
    float temp_f3_2 = v1.z;
    float temp_f1_3 = v2.x;
    float temp_f6 = v2.y;
    float temp_f4_2 = v2.z;

    nlMatrix3 mat;
    mat.m[0] = v1.x;
    mat.m[1] = v1.y;
    mat.m[2] = v1.z;
    mat.m[3] = v2.x;
    mat.m[4] = v2.y;
    mat.m[5] = v2.z;
    mat.m[6] = (temp_f5 * temp_f4_2) - (temp_f3_2 * temp_f6);
    mat.m[7] = (-temp_f7 * temp_f4_2) + (temp_f3_2 * temp_f1_3);
    mat.m[8] = (temp_f7 * temp_f6) - (temp_f5 * temp_f1_3);

    dSpaceID space = NULL;
    if (collision_space != NULL)
    {
        space = collision_space->m_spaceID;
    }

    // m_geomID = dCreateFinitePlane(space, m_vec4.x, m_vec4.y, m_vec4.z, m_vec4.w, arg5, m_param);
    m_geomID = dCreateFinitePlane(space, m_vec4.y, m_vec4.z, m_vec4.w, m_param, arg5, m_param);
    dGeomSetData(m_geomID, this);
    SetRotation(mat);
    SetPosition(pos, CoordinateType_0);
    SetDefaultCollideBits();
}
