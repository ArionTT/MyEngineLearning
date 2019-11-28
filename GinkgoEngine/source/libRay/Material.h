#pragma once

#include<Vector.h>

#include"Ray.h"
#include"Hitable.h"
#include"RayTexture.h"

namespace External
{
	struct Vector3;

	// ��λcube���ȡ��,����һ�������ڵĵ�
	Vector3 random_in_unit_sphere();

	bool refract(const Vector3& v, const Vector3& n, float ni_over_nt, Vector3& refracted);

	float schlick(float cosine, float ref_idx);

	//����
	Vector3 reflect(const Vector3& v, const Vector3& n);

	class Material
	{
	public:
		// ɢ���麯��
		// ������r_in ����Ĺ��ߣ� rec hit�ļ�¼�� attenuation v3��˥����scattered ɢ���Ĺ���
		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered) = 0;

		// ���Է�����ʣ�Ĭ�Ϸ��غ�ɫ
		virtual Vector3 emitted(float u, float v, Vector3 &p) { return Vector3(0, 0, 0); }
	};


	class LambertianMat : public Material
	{
	public:
		ray_texture* albedo;    // ������

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


	//�����
	class DielectricMat : public Material
	{
	public:
		float ref_idx;
		float fuzz;

	public:
		DielectricMat(float ri, float _fuzz) : ref_idx(ri), fuzz(_fuzz) {}

		virtual bool scatter(const Ray& r_in, HitRecord& rec, Vector3& attenuation, Ray& scattered);
	};

	// �Է������
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