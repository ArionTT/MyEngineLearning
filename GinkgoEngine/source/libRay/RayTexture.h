#pragma once

#include<Vector.h>
#include<Math.h>

#include"noise.h"

namespace External
{
	class ray_texture
	{
	public:
		virtual Vector3 value(float u, float v, Vector3 &p) = 0;
	};

	class constant_texture : public ray_texture
	{
	public:
		Vector3 color;

	public:
		constant_texture() {}

		constant_texture(Vector3 c) : color(c) {}

		virtual Vector3 value(float u, float v, Vector3 &p);

	};


	// ��������
	class checker_texture :public ray_texture
	{
	public:
		// ��������ļ����ɫ
		ray_texture *odd;
		ray_texture *even;

	public:
		checker_texture() {}
		checker_texture(ray_texture *t0, ray_texture *t1) :even(t0), odd(t1) {}

		virtual Vector3 value(float u, float v, Vector3 &p);

	};

	Vector3 clampVector3(Vector3 _v);

	// ��������
	class noise_texture :public ray_texture
	{
	public:
		perlin noise;
		float scale;

	public:
		noise_texture() {}
		noise_texture(float sc) :scale(sc) {}
		virtual Vector3 value(float u, float v, Vector3& p)
		{
			//PPM��ʽ��֧����ɫֵ����1.0��С��0.0�Զ�ȡ[0,1]����
			return clampVector3(Vector3(1, 1, 1)*0.5*(1 + sin(scale*p.x) + 5 * noise.noise(p)));
		}

	};



	class image_texture : public ray_texture
	{
	public:
		unsigned char *data;
		int nx, ny;

	public:
		image_texture() {}
		image_texture(unsigned char *pixels, int A, int B) : data(pixels), nx(A), ny(B) {}
		virtual Vector3 value(float u, float v, Vector3& p);


	};
}