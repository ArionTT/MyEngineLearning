#include "RayTexture.h"

namespace External
{
	Vector3 constant_texture::value(float u, float v, Vector3 & p)
	{
		return color;
	}

	Vector3 checker_texture::value(float u, float v, Vector3 & p)
	{
		float sines = sin(10 * p.x)*sin(10 * p.y)*sin(10 * p.z);
		if (sines < 0)
			return odd->value(u, v, p);
		else
			return  even->value(u, v, p);
	}

	Vector3 image_texture::value(float u, float v, Vector3 & p)
	{
		int i = (1 - u)*nx;
		int j = (1 - v)*ny - 0.001;
		if (i < 0) i = 0;
		if (j < 0) j = 0;
		if (i > nx - 1) i = nx - 1;
		if (j > ny - 1) j = ny - 1;
		float r = int(data[3 * i + 3 * nx*j]) / 255.0;
		float g = int(data[3 * i + 3 * nx*j + 1]) / 255.0;
		float b = int(data[3 * i + 3 * nx*j + 2]) / 255.0;
		return Vector3(r, g, b);
	}

	Vector3 clampVector3(Vector3 v)
	{
		if (v.x > 1.0f || v.y > 1.0f || v.z > 1.0f)
		{
			return Vector3(clamp(v.x), clamp(v.y), clamp(v.z));
		}
		else if (v.x < 0.0f || v.y < 0.0f || v.z < 0.0f)
		{
			return Vector3(clamp(v.x), clamp(v.y), clamp(v.z));
		}
		else
		{
			return v;
		}
	}

}


