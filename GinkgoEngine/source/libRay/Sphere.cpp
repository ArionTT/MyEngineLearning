#include "Sphere.h"

namespace External
{
	bool Sphere::hit(const Ray & r, float t_min, float t_max, HitRecord & record)
	{
		Vector3 cen(center);
		Vector3 o(r.origin);
		Vector3 oc(o - cen);
		float a = Vector3::Dot(r.dir, r.dir);
		float b = Vector3::Dot(oc, r.dir);
		float c = Vector3::Dot(oc, oc) - radius * radius;
		float discriminant = b * b - a * c;
		if (discriminant > 0) {
			float temp = (-b - sqrt(discriminant)) / a;
			if (temp < t_max && temp > t_min) {
				record.t = temp;
				Ray _r = r;
				record.pos = _r.ray_point(record.t);
				record.normal = (record.pos - center) / radius;
				record.matPtr = this->matPtr;
				return true;
			}
			//temp = (-b + sqrt(discriminant)) / a;
			//if (temp < t_max && temp > t_min) {
			//	record.t = temp;
			//	record.pos = r.ray_point(record.t);
			//	record.normal = (record.pos - center) / radius;
			//	return true;
			//}
		}
		return false;
	}
	bool Sphere::bounding_box(float t0, float t1, Aabb & box)
	{
		box = Aabb(center - Vector3(radius, radius, radius), center + Vector3(radius, radius, radius));
		return true;
	}
}


