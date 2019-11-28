#include "Ray.h"

namespace External
{
	Ray::Ray()
	{
		origin.a[0] = origin.a[1] =
			origin.a[2] = 0.0f;
		dir.a[0] = dir.a[1] = 0.0f;
		dir.a[2] = 1.0f;
	}

	Ray::Ray(const Vector3 & o, const Vector3 & d)
	{
		origin.a[0] = o.a[0];
		origin.a[1] = o.a[1];
		origin.a[2] = o.a[2];
		dir.a[0] = d.a[0];
		dir.a[1] = d.a[1];
		dir.a[2] = d.a[2];
	}

	Ray::Ray(const Ray & r)
	{
		origin.a[0] = r.origin.a[0];
		origin.a[1] = r.origin.a[1];
		origin.a[2] = r.origin.a[2];
		dir.a[0] = r.dir.a[0];
		dir.a[1] = r.dir.a[1];
		dir.a[2] = r.dir.a[2];
	}

	Vector3 Ray::ray_point(float t)
	{
		return origin + dir * t;
	}

}


