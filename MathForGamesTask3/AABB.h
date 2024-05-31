#pragma once
#include "Vector3.h"
#include <vector>
#include "Utils.h"

struct AABB {
	AABB() {}
	AABB(const math::Vector3& min, const math::Vector3& max) : min(min), max(max) {}

	math::Vector3 min, max;
	Utils utils;

	void SetVars(const math::Vector3& _min, const math::Vector3& _max) {
		min = _min;
		max = _max;
		//std::cout << "Set min to " << _min.ToString() << " and max to " << _max.ToString() << "\n";
	}

	math::Vector3 Center() const {
		return (min + max) * 0.5f;
	}

	std::vector<math::Vector3> Corners() const {
		std::vector<math::Vector3> corners(4);

		corners[0] = min;
		corners[1] = { min.x, max.y, 0 };
		corners[2] = max;
		corners[3] = { max.x, min.y, 0 };
	}

	void fit(const math::Vector3* points, unsigned int count) {
		min = { FLT_MAX, FLT_MAX, 0 };
		max = { FLT_MIN, FLT_MIN, 0 };

		for (unsigned int i = 0; i < count; i++, ++points) {
			min = utils.min(min, *points);
			max = utils.max(max, *points);
		}

	}

	void Fit(const std::vector<math::Vector3>& points) {
		min = { FLT_MAX, FLT_MAX, 0 };
		max = { -FLT_MAX, -FLT_MAX, 0 };

		for (auto& p : points) {
			min = utils.min(min, p);
			max = utils.max(max, p);
		}
	}

	bool Overlaps(const math::Vector3& p) const
	{
		return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
	}

	bool Overlaps(const AABB& other) const {
		return !(max.x < other.min.x || max.y < other.min.y || min.x > other.max.x || min.y > other.max.y);
	}

	math::Vector3 ClosestPoint(const math::Vector3& p) {
		return utils.clamp(p, min, max);
	}
};

