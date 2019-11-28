#pragma once

#include <Vector.h>

#include"Hitable.h"
#include"Material.h"
#include"Ray.h"
#include"Aabb.h"

namespace External
{
	struct Sphere: public Hitable
	{
	public:
		Vector3 center;
		float radius;
		Material* matPtr;

	public:
		Sphere() {}
		Sphere(const Vector3& c, const float r, Material* matPtr) { 
			this->center = c; 
			this->radius = r; 
			this->matPtr = matPtr; 
		}

	public:
		// Í¨¹ý hitable ¼Ì³Ð
		virtual bool hit(const Ray & r, float t_min, float t_max, HitRecord & record) override;

		virtual bool bounding_box(float t0, float t1, Aabb &box) override;
	};

}