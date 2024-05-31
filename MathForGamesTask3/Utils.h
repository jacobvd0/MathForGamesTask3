#pragma once
#include "Vector3.h"
#include <vector>

using namespace math;
class Utils
{
public:
	constexpr float min(float a, float b) { return a < b ? a : b; }
	constexpr float max(float a, float b) { return a > b ? a : b; }


	Vector3 min(const Vector3& a, const Vector3& b) {
		return Vector3(min(a.x, b.x), min(a.y, b.y), 0);
	}

	Vector3 max(const Vector3& a, const Vector3& b) {
		return Vector3(max(a.x, b.x), max(a.y, b.y), 0);
	}

	constexpr float clamp(float t, float a, float b) {
		return max(a, min(b, t));
	}
	Vector3 clamp(const Vector3& t, const Vector3& a, const Vector3& b) {
		return max(a, min(b, t));
	}
};


