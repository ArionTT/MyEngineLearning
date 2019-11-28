#include "RayTrace.h"

#include"Ray.h"
#include"Hitable.h"
#include"RayCamera.h"
#include"Material.h"

namespace External
{
	Vector3 bg_color = Vector3(0.125f, 0.4532f, 0.758f);// vec3(0.85f, 0.45f, 0.12f);
	Vector3 bad_color = Vector3(0.9f, 0.0f, 0.9f);

	int RayTracer::depth_max = 200;


	Ray RayTracer::generateRay(const RayCamera & _camera, float _u, float _v)
	{
		Vector3 h = _camera.horizon;
		Vector3 v = _camera.vertical;
		Vector3 c = _camera.low_left_corner;
		Vector3 uv_point = c + h * _u + v * _v;
		Vector3 dir = uv_point - _camera.origin;
		return Ray(_camera.origin, dir);
	}

	Vector3 RayTracer::rayTrace(const Ray & _ray, Hitable_list* _scene, int _depth)
	{
		HitRecord rec;
		if (_scene->hit(_ray, 0.0f, FLT_MAX, rec))
		{
			// É¢ÉäºóµÄ¹âÏß
			Ray scattered;
			// Ë¥¼õ
			Vector3 attenuation;

			if (_depth < depth_max && rec.matPtr->scatter(_ray, rec, attenuation, scattered))
			{
				// µÝ¹é Ë¥¼õ
				return  rayTrace(scattered, _scene, _depth + 1)* attenuation;
			}
			else
			{
				return Vector3(0, 0, 0);
			}
		}
		else
		{
			Vector3 nDir = Vector3::Normalize(_ray.dir);
			float tt = 0.5f *(nDir.y + 1.0f);
			return Vector3::One()*(1.0f - tt) + bg_color * tt;
		}
	}

}


