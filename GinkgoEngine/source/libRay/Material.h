#pragma once

#include<Vector.h>

#include"Ray.h"
#include"Hitable.h"
#include"RayTexture.h"

namespace External
{
	struct Vector3;

	// 单位cube随机取点,返回一个在球内的点
	Vector3 random_in_unit_sphere();

	bool refract(const Vector3& v, const Vector3& n, float ni_over_nt, Vector3& refracted);

	float schlick(float cosine, float ref_idx);

	//反射
	Vector3 reflect(const Vector3& v, const Vector3& n);

	class Material
	{
	public:
		// 散射虚函数
		// 参数：r_in 入射的光线， rec hit的记录， attenuation v3的衰减，scattered 散射后的光线
		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered) = 0;

		// 非自发光材质，默认返回黑色
		virtual Vector3 emitted(float u, float v, Vector3 &p) { return Vector3(0, 0, 0); }
	};


	class LambertianMat : public Material
	{
	public:
		ray_texture* albedo;    // 反射率

	public:
		//lambertian(const vec3& a) : albedo(a) {}
		LambertianMat(ray_texture* tex) : albedo(tex) {}

		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered);

	};


	class MetalMat : public Material
	{
	public:
		Vector3 albedo;
		float fuzz;

	public:
		//Fuzz = roughness _fuzz =0 ====> Smooth
		MetalMat(const Vector3& a, float _fuzz) : albedo(a) { if (_fuzz < 1) fuzz = _fuzz; else fuzz = 1; }

		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered);

	};


	//电解质
	class DielectricMat : public Material
	{
	public:
		float ref_idx;
		float fuzz;

	public:
		DielectricMat(float ri, float _fuzz) : ref_idx(ri), fuzz(_fuzz) {}

		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered);
	};

	// 自发光材质
	class DiffuseLightMat :public Material
	{
	public:
		ray_texture *emit;

	public:
		DiffuseLightMat(ray_texture *a) :emit(a) {}

		virtual bool scatter(const Ray& r_in, const HitRecord &rec, Vector3 & attenuation, Ray& scattered);

		virtual Vector3 emitted(float u, float v, Vector3 &p);

	};

}