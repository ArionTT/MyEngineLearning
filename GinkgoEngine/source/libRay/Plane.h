//
//#ifndef PLANE_H
//#define PLANE_H
//
//#include <vector>
//
//#include<Vector.h>
//
//
//namespace External
//{
//
//	struct Plane
//	{
//	public:
//		//三点创建一个平面
//		static void CreatePlane(Vector3 p1, Vector3 p2, Vector3 p3, Plane* plane);
//
//	public:
//		Plane();
//
//	protected:
//		//由点列表计算出最佳法向量
//		Vector3 computeBestFitNormal(std::vector<Vector3> list);
//		//由点列表计算出最佳偏移量
//		float computeBestFitD(std::vector<float> list);
//		//计算点到平面的距离
//		float computePointDistance(Vector3 point);
//
//	public:
//		Vector3 normal;
//		float d;
//	};
//
//}
//
//#endif // !PLANE_H
//
