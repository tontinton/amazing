#include "Math.hpp"
#include "Interfaces.h"

namespace Math
{
    void NormalizeAngles(QAngle& angles)
    {
        for (auto i = 0; i < 3; i++) {
            while (angles[i] < -180.0f) angles[i] += 360.0f;
            while (angles[i] >  180.0f) angles[i] -= 360.0f;
        }
    }
    //--------------------------------------------------------------------------------
    void ClampAngles(QAngle& angles)
    {
        if (angles.pitch > 89.0f) angles.pitch = 89.0f;
        else if (angles.pitch < -89.0f) angles.pitch = -89.0f;

        if (angles.yaw > 180.0f) angles.yaw = 180.0f;
        else if (angles.yaw < -180.0f) angles.yaw = -180.0f;

        angles.roll = 0;
    }
    //--------------------------------------------------------------------------------
    void VectorTransform(const Vector& in1, const matrix3x4_t& in2, Vector& out)
    {
        out[0] = in1.Dot(in2[0]) + in2[0][3];
        out[1] = in1.Dot(in2[1]) + in2[1][3];
        out[2] = in1.Dot(in2[2]) + in2[2][3];
    }
    //--------------------------------------------------------------------------------
    static bool screen_transform(const Vector& in, Vector& out)
    {
        static auto& w2sMatrix = Interfaces::g_engineClient->WorldToScreenMatrix();

        out.x = w2sMatrix.m[0][0] * in.x + w2sMatrix.m[0][1] * in.y + w2sMatrix.m[0][2] * in.z + w2sMatrix.m[0][3];
        out.y = w2sMatrix.m[1][0] * in.x + w2sMatrix.m[1][1] * in.y + w2sMatrix.m[1][2] * in.z + w2sMatrix.m[1][3];
        out.z = 0.0f;

        float w = w2sMatrix.m[3][0] * in.x + w2sMatrix.m[3][1] * in.y + w2sMatrix.m[3][2] * in.z + w2sMatrix.m[3][3];

        if (w < 0.001f) {
            out.x *= 100000;
            out.y *= 100000;
            return false;
        }

        out.x /= w;
        out.y /= w;

        return true;
    }
    //--------------------------------------------------------------------------------
    bool WorldToScreen(const Vector& in, Vector& out)
    {
        if (screen_transform(in, out)) {
            int w, h;
            Interfaces::g_engineClient->GetScreenSize(w, h);

            out.x = (w / 2.0f) + (out.x * w) / 2.0f;
            out.y = (h / 2.0f) - (out.y * h) / 2.0f;

            return true;
        }
        return false;
    }
    //--------------------------------------------------------------------------------
}
