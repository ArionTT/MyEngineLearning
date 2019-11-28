#ifndef BOUND_H
#define BOUND_H

#include<Vector.h>
#include<Matrix4x4.h>
#include<stdhead.h>

namespace External
{
	struct Bound
	{

	};

	struct AABB :public Bound
	{
	public:
		Vector3 max;
		Vector3 min;
	};

	struct OBB :public Bound
	{
	public:
		Matrix4x4 mtx;
		Vector3 max;
		Vector3 min;

	};

	struct Sphere : public Bound
	{
	public:
		Vector3 origin;
		float radius;

	};

}

#endif // !BOUND_H





