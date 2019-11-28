#pragma once

#include<Vector.h>
#include"Ray.h"
#include"Hitable.h"
#include"RayCamera.h"

namespace External
{
	class RayTracer
	{
	public:
		static Ray generateRay(const RayCamera& _camera, float _u, float _v);

		static Vector3 rayTrace(const Ray& _ray, Hitable_list*_scene, int _depth);

	public:
		static int depth_max;
		static Vector3 bg_color;
		static Vector3 bad_color;


	};

}
