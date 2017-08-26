#pragma once

#define RAD2DEG(x) DirectX::XMConvertToDegrees(x)
#define DEG2RAD(x) DirectX::XMConvertToRadians(x)
#include "valve_sdk/Math/QAngle.hpp"

class matrix3x4_t;
class Vector;

namespace Math
{
	void NormalizeAngles(QAngle& angles);
	void ClampAngles(QAngle& angles);
	void VectorTransform(const Vector& in1, const matrix3x4_t& in2, Vector& out);
	bool WorldToScreen(const Vector& in, Vector& out);
}
