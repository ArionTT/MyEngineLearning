#pragma once

#include<Vector.h>
#include<Math.h>

#include"Ray.h"


namespace External
{
	class RayCamera
	{
	public:
		Vector3 low_left_corner;
		Vector3 horizon;
		Vector3 vertical;
		Vector3 origin;

	public:
		RayCamera();

		//aspect = w/h
		RayCamera(Vector3& lookfrom, Vector3& lookat, Vector3 vup, float vfov, float aspect);

		RayCamera(Vector3& forward, Vector3& up, float fov, float aspect);

		Vector3 GetRayDir(float _u, float _v);

	};
}