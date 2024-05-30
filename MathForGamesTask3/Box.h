#pragma once
#include "Vector3.h"
#include <vector>

using namespace math;

class Box
{
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
	
	struct AABB {
		AABB() {}
		AABB(const Vector3& min, const Vector3& max) : min(min), max(max) {}

		Vector3 min, max;


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
			min = {FLT_MAX, FLT_MAX, 0};
			max = { FLT_MIN, FLT_MIN, 0 };
			
			for (unsigned int i = 0; i < count; i++, ++points) {
				min = ::min(min, *points);
				max = ::max(max, *points);
			}


		}

		bool Overlaps(const Vector3& p) const
		{
			// test for not overlapped as it exits faster
			return !(p.x < min.x || p.y < min.y ||
				p.x > max.x || p.y > max.y);
		}


	};

	
};

