#pragma once
#include "Vector3.h"
#include <vector>

class Utils
{
public:
	constexpr float min(float a, float b) { return a < b ? a : b; }
	constexpr float max(float a, float b) { return a > b ? a : b; }


	math::Vector3 min(const math::Vector3& a, const math::Vector3& b) {
		return math::Vector3(min(a.x, b.x), min(a.y, b.y), 0);
	}

	math::Vector3 max(const math::Vector3& a, const math::Vector3& b) {
		return math::Vector3(max(a.x, b.x), max(a.y, b.y), 0);
	}

	constexpr float clamp(float t, float a, float b) {
		return max(a, min(b, t));
	}
	math::Vector3 clamp(const math::Vector3& t, const math::Vector3& a, const math::Vector3& b) {
		return max(a, min(b, t));
	}
};


