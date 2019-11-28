#include "RayCamera.h"

namespace External
{

	RayCamera::RayCamera()
	{
		low_left_corner = Vector3(-2, -1, -1);
		horizon = Vector3(4, 0, 0);
		vertical = Vector3(0, 2, 0);
		origin = Vector3(0, 0, 0);
	}

	RayCamera::RayCamera(Vector3 & lookfrom, Vector3 & lookat, Vector3 vup, float vfov, float aspect)
	{
		Vector3 u, v, w;
		float theta = vfov * PI / 180.0f;
		float half_height = tan(theta / 2.0f);
		float half_width = aspect * half_height;
		origin = lookfrom;
		Vector3 temp = origin - lookat;

		w = Vector3::Normalize(temp);//fornt
		temp = Vector3::Cross(vup, w);
		u = Vector3::Normalize(temp);//right
		v = Vector3::Cross(w, u);//up

		//low_left_corner = Vector3(-half_width, -half_height, -1.0);
		low_left_corner = origin - u * half_width - v * half_height - w;
		horizon = u * 2.0f * half_width;
		vertical = v * 2.0f * half_height;
	}

	RayCamera::RayCamera(Vector3 & forward, Vector3 & up, float fov, float aspect)
	{
	}

	Vector3 RayCamera::GetRayDir(float _u, float _v)
	{
		return Vector3();
	}

}

