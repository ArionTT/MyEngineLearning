#include "Material.h"

#include"drand48.h"


#include<Math.h>

namespace External
{
	Vector3 random_in_unit_sphere() {
		Vector3 p;
		do {
			p = Vector3(drand48(), drand48(), drand48())*2.0f - Vector3(1, 1, 1);
		} while (Vector3::Dot(p, p) >= 1.0);
		return p;
	}
	Vector3 reflect(const Vector3 & v, const  Vector3 & n) {
		Vector3 _n = n;
		Vector3 _v = v;
		return _v - _n * 2 * Vector3::Dot(v, n);
	}
	bool refract(const Vector3 & v, const Vector3 & n, float ni_over_nt, Vector3 & refracted) {
		Vector3 _n = n;
		Vector3 _v = v;
		Vector3 uv = Vector3::Normalize(v);
		float dt = Vector3::Dot(uv, n);
		float discriminant = 1.0 - ni_over_nt * ni_over_nt*(1 - dt * dt);
		if (discriminant > 0) {
			refracted = (uv - _n * dt) * ni_over_nt - _n * External::sqrt(discriminant);
			return true;
		}
		else {
			return false;
		}
	}
	float schlick(float cosine, float ref_idx) {
		float r0 = (1 - ref_idx) / (1 + ref_idx);
		r0 = r0 * r0;
		return r0 + (1 - r0)* External::pow((1 - cosine), 5);
	}
	bool LambertianMat::scatter(const Ray & r_in, HitRecord & rec, Vector3 & attenuation, Ray & scattered)
	{
		Vector3 target = rec.pos + rec.normal + random_in_unit_sphere();
		scattered = Ray(rec.pos, target - rec.pos);
		attenuation = albedo->value(0, 0, rec.pos);
		return true;
	}
	bool MetalMat::scatter(const Ray & r_in, HitRecord & rec, Vector3 & attenuation, Ray & scattered)
	{
		Vector3 n_dir = Vector3::Normalize(r_in.dir);
		Vector3 reflected = reflect(n_dir, rec.normal);
		scattered = Ray(rec.pos, reflected + random_in_unit_sphere()*fuzz);
		attenuation = albedo;
		return (Vector3::Dot(scattered.dir, rec.normal) > 0);
	}
	bool DielectricMat::scatter(const Ray & r_in, HitRecord & rec, Vector3 & attenuation, Ray & scattered)
	{
		Vector3 outward_normal;
		Vector3 reflected = reflect(r_in.dir, rec.normal);
		float ni_over_nt;
		attenuation = Vector3(1.0, 1.0, 1.0);
		Vector3 refracted;
		float reflect_prob;
		float cosine;
		//判断内部和外部
		Vector3 _dir = r_in.dir;
		if (Vector3::Dot(r_in.dir, rec.normal) > 0)
		{
			outward_normal = rec.normal*-1;
			ni_over_nt = ref_idx;
			//         cosine = ref_idx * dot(r_in.direction(), rec.normal) / r_in.direction().length();
			cosine = Vector3::Dot(r_in.dir, rec.normal) / _dir.magnitude();
			cosine = sqrt(1 - ref_idx * ref_idx*(1 - cosine * cosine));
		}
		else
		{
			outward_normal = rec.normal;
			ni_over_nt = 1.0 / ref_idx;
			cosine = -Vector3::Dot(r_in.dir, rec.normal) / _dir.magnitude();
		}

		if (refract(r_in.dir, outward_normal, ni_over_nt, refracted))
			reflect_prob = schlick(cosine, ref_idx);
		else
			reflect_prob = 1.0;

		// 随机数小与反射系数，设为反射光线，反之为折射光线
		if (drand48() < reflect_prob)
			scattered = Ray(rec.pos, reflected + random_in_unit_sphere()*fuzz);
		else
			scattered = Ray(rec.pos, refracted + random_in_unit_sphere()*fuzz);

		return true;
	}
	bool DiffuseLightMat::scatter(const Ray & r_in, const HitRecord & rec, Vector3 & attenuation, Ray & scattered)
	{
		return false;
	}
	Vector3 DiffuseLightMat::emitted(float u, float v, Vector3 & p)
	{
		return emit->value(u, v, p);
	}
}


