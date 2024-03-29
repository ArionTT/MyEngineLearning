#include "Hitable.h"
#include"Ray.h"
#include"Aabb.h"

#include<Vector.h>

namespace External
{
	bool Hitable_list::hit(const Ray & r, float tmin, float tmax, HitRecord & rec)
	{
		HitRecord temp_rec;
		bool hit_anything = false;
		double closest_so_far = tmax;
		for (int i = 0; i < list_size; i++) {
			if (list[i]->hit(r, tmin, closest_so_far, temp_rec)) {
				hit_anything = true;
				closest_so_far = temp_rec.t;
				rec = temp_rec;
			}
		}
		return hit_anything;
	}

	bool Hitable_list::bounding_box(float t0, float t1, Aabb & box)
	{
		return true;
	}

}


