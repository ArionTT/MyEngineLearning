#include "Aabb.h"

namespace External
{
	Aabb::Aabb(Vector3 a, Vector3 b)
	{
		min = a; max = b;
	}
	bool Aabb::hit(Ray & r, float tmin, float tmax)
	{
		for (int a = 0; a < 3; a++)
		{
			float invD = 1.0f / r.dir.a[a];
			float t0 = (min[a] - r.dir[a]) * invD;
			float t1 = (max[a] - r.dir[a]) * invD;

			if (invD < 0.0f)
			{
				//std::swap(t0, t1);
				float tt = t0;
				t0 = t1;
				t1 = tt;
			}
			tmin = t0 > tmin ? t0 : tmin;
			tmax = t1 < tmax ? t1 : tmax;
			if (tmax <= tmin)
				return false;
		}
		return true;
	}
}


