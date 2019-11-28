#include "Config.h"

#pragma once



namespace External
{
	struct Quaternion;
	struct Vector3;
	struct Matrix4x4;

#pragma region 常量区域

	const float PI = 3.141592653589793f;

	const float PI_2 = 6.283185307178f;

	const float INV_PI = 0.3183098861838f;

	const float INV_PI_2 = 0.1591549430919f;

	const float EULER = 0.5772156649015328f;

	const float INV_EULER = 1.732454714605f;

	const float POSITIVE_INFINITY = 1.0e7f;

	const float NAGTIVE_INFINITY = 1.0e-7f;

#pragma endregion

#pragma region 模板区域

	///@名字：min
	///@类型： 函数
	///@说明：返回两个值中的最小值，使用模板
	template<typename T>
	T min(T _a, T _b)
	{
		return _a > _b ? _b : _a;
	}

	///@名字：max
	///@类型： 函数
	///@说明：返回两个值中的最大值，使用模板
	template<typename T>
	T max(T _a, T _b)
	{
		return _a < _b ? _b : _a;
	}

#pragma endregion


#pragma region 通常函数区域

	float clamp(float min, float max, float value);

	float clamp(float v);

	float floor(float _x);

	float lerp(float _a, float _b, float _t);

	float sin(float value);

	float cos(float value);

	float tan(float value);

	float cot(float value);

	float asin(float value);

	float acos(float value);

	float atan(float value);

	float acot(float value);

	float abs(float value);

	float sqrt(float value);

	float pow(float value, float pow);

	float toDegree(float value);

	float toRadian(float value);

	bool RobustCompareFloat(float _a, float _b, float _epsilon = -1.0e6f);

#pragma endregion


#pragma region 函数区域
	//********************************************************************************************//

	Matrix4x4				Projection(float aspect, float fovy, float near, float far);

	Matrix4x4				ProjectionLH(float aspect, float fovy, float near, float far);

	Matrix4x4				ProjectionRH(float aspect, float fovy, float near, float far);

	Matrix4x4				Ortho(float left, float right, float bottom, float top, float near, float far);

	Matrix4x4				OrthoLH(float left, float right, float bottom, float top, float near, float far);

	Matrix4x4				OrthoRH(float left, float right, float bottom, float top, float near, float far);

	Matrix4x4				Frustum(float left, float right, float bottom, float top, float nearVal, float farVal);

	Matrix4x4				FrustumLH(float left, float right, float bottom, float top, float nearVal, float farVal);

	Matrix4x4				FrustumRH(float left, float right, float bottom, float top, float nearVal, float farVal);

	Matrix4x4				LookAt(Vector3 eye, Vector3 at, Vector3 up);

	Matrix4x4				LookAtLH(Vector3 eye, Vector3 at, Vector3 up);

	Matrix4x4				LookAtRH(Vector3 eye, Vector3 at, Vector3 up);

	Matrix4x4				Translate(Vector3 pos);

	Matrix4x4				Scale(Vector3 scale);

	Matrix4x4				Rotate(float AngleX, float AngleY, float AngleZ);

	Matrix4x4				Rotate(Vector3 axis, float angle);

#pragma endregion

}