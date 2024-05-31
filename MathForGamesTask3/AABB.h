#pragma once
#include "Vector3.h"
#include <vector>
#include "Utils.h"

using namespace math;

struct AABB {
	AABB() {}
	AABB(const Vector3& min, const Vector3& max) : min(min), max(max) {}

	Vector3 min, max;
	Utils utils;

	Vector3 Center() const {
		return (min + max) * 0.5f;
	}

	std::vector<Vector3> Corners() const {
		std::vector<Vector3> corners(4);

		corners[0] = min;
		corners[1] = { min.x, max.y, 0 };
		corners[2] = max;
		corners[3] = { max.x, min.y, 0 };
	}

	void fit(const Vector3* points, unsigned int count) {
		min = { FLT_MAX, FLT_MAX, 0 };
		max = { FLT_MIN, FLT_MIN, 0 };

		for (unsigned int i = 0; i < count; i++, ++points) {
			min = utils.min(min, *points);
			max = utils.max(max, *points);
		}

	}

	void Fit(const std::vector<Vector3>& points) {
		min = { FLT_MAX, FLT_MAX, 0 };
		max = { -FLT_MAX, -FLT_MAX, 0 };

		for (auto& p : points) {
			min = utils.min(min, p);
			max = utils.max(max, p);
		}
	}

	bool Overlaps(const Vector3& p) const
	{
		return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
	}

	Vector3 ClosestPoint(const Vector3& p) {
		return utils.clamp(p, min, max);
	}
};

