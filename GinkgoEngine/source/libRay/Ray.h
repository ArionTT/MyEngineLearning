#ifndef RAY_H
#define RAY_H

#include<Vector.h>

namespace External
{
	struct Ray
	{
	public:
		Vector3 origin;
		Vector3 dir;

	public:
		Ray();
		Ray(const Vector3& o, const Vector3& d);
		Ray(const Ray& r);
		Vector3 ray_point(float t);

	};

}

#endif // !RAY_H

