#pragma once

#include <Vector.h>

#include"Ray.h"

namespace External
{
	struct Aabb
	{
	public:
		Vector3 min;
		Vector3 max;

	public:
		Aabb() {}
		Aabb(Vector3 a, Vector3 b);

		bool hit(Ray& r, float tmin, float tmax);

	};
}