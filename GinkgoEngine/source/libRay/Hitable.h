#pragma once

#include<Vector.h>

namespace External
{
	class Material;
	struct Ray;
	struct Aabb;
	struct Vector3;

	struct HitRecord
	{
		float t;
		Vector3 pos;
		Vector3 normal;
		Material* matPtr;
	};

	class Hitable
	{
	public:
		virtual bool hit(const Ray& r, float t_min, float t_max, HitRecord& record) = 0;
		virtual bool bounding_box(float t0, float t1, Aabb & box) = 0;

	};

	class Hitable_list
	{
	public:
		Hitable **list;
		int list_size;

	public:
		Hitable_list() {}
		Hitable_list(Hitable **l, int n) { list = l; list_size = n; }

		virtual bool hit(const Ray& r, float tmin, float tmax, HitRecord& rec);

		virtual bool bounding_box(float t0, float t1, Aabb & box);

	};

}