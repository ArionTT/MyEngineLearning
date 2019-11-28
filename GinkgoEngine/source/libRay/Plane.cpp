//#include "Plane.h"
//
//
//namespace External
//{
//
//	void Plane::CreatePlane(Vector3 p1, Vector3 p2, Vector3 p3, Plane* plane)
//	{
//		Vector3 e3 = p2 - p1;
//		Vector3 e1 = p3 - p2;
//
//		plane->normal = Vector3::Cross(e3, e1);
//		plane->normal.normalize();
//		plane->d = Vector3::Dot(plane->normal, e3);
//	}
//
//	Plane::Plane()
//	{
//		normal = Vector3::One();
//		d = 0.0f;
//	}
//
//
//	Vector3 Plane::computeBestFitNormal(std::vector<Vector3> list)
//	{
//		Vector3 result = Vector3::Zero();
//
//		const Vector3*p1 = &list[list.size() - 1];
//
//		for (int i = 0; i < list.size(); i++)
//		{
//			const Vector3 *p2 = &list[list.size()];
//
//			result += Vector3((p1->z + p2->z)*(p1->y - p2->y), (p1->x + p2->x)*(p1->z - p2->z), (p1->y + p2->y)*(p1->x - p2->x));
//		}
//		result.normalize();
//
//		return result;
//	}
//
//	float Plane::computeBestFitD(std::vector<float> list)
//	{
//		float result = 0.0f;
//
//		for (int i = 0; i < list.size(); i++)
//		{
//			result += list[i];
//		}
//
//		return result / list.size();
//	}
//
//	float Plane::computePointDistance(Vector3 point)
//	{
//		return Vector3::Dot(point, normal) - d;
//	}
//
//
//
//}