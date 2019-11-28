#include"Vector.h"
#include"Matrix4x4.h"
#include"Quaternion.h"

#include "Math.h"

//#include <cmath>
#include<iostream>
#include<math.h>
#include<string>

namespace External
{
	std::string aaa = "123";

	const float PI_2__INV__360_DEGREE = PI_2 / 360.0f;

	const float DEGREE_360__INV__PI_2 = 360.0f / PI_2;

	float clamp(float min, float max, float value)
	{
		float out = min;
		if (value > min)
			out = value;
		if (value < max)
			out = max;
		return out;
	}

	float clamp(float f)
	{
		if (f > 1.0f)
		{
			return 1.0f;
		}
		else if (f < 0.0f)
		{
			return 0.0f;
		}
		else
		{
			return f;
		}
	}

	float floor(float _x)
	{
		int x = (int)_x;
		return (float)x;
	}

	float lerp(float _a, float _b, float _t)
	{
		return (_a - _b)*_t + _b;
	}

	float sin(float value)
	{
		return sinf(value);
	}

	float cos(float value)
	{
		return cosf(value);
	}

	float tan(float value)
	{
		return tanf(value);
	}

	float cot(float value)
	{
		return 0.0f;
	}

	float asin(float value)
	{
		return asinf(value);
	}

	float acos(float value)
	{
		return acosf(value);
	}

	float atan(float value)
	{
		return atanf(value);
	}

	float acot(float value)
	{
		return 0.0f;
	}

	float abs(float _value)
	{
		//return abs((double)value);
		return _value > 0 ? _value : -_value;
	}

	float sqrt(float value)
	{
		return sqrtf(value);
	}

	float pow(float value, float pow)
	{
		//return pow(value, pow);
		return 0.0f;
	}

	float toDegree(float value)
	{
		return (value)*DEGREE_360__INV__PI_2;
	}

	float toRadian(float value)
	{
		return (value)*PI_2__INV__360_DEGREE;
	}

	bool RobustCompareFloat(float _a, float _b, float _epsilon)
	{
		const float eps_0 = _epsilon < 0.0f ? 1.0e-6f : _epsilon, rel_error = 10e-4f;
		bool isEqualFlag = false;
		if (fabs(_a - _b) <= eps_0)
		{
			isEqualFlag = true;
		}
		else
		{
			if (fabs(_a) >= 1000.0f)
			{
				if (fabs(_a - _b) <= rel_error * fabs(_a))
				{
					isEqualFlag = true;
				}
			}
		}
		return isEqualFlag;
	}

	Matrix4x4 Projection(float aspect, float fovy, float near, float far)
	{
#if GRAPHIC_LEFT_HAND_SYSTEM
		return ProjectionLH(aspect, fovy, near, far);
#elif GRAPHIC_RIGHT_HAND_SYSTEM 
		return ProjectionRH(aspect, fovy, near, far);
#endif
	}

	Matrix4x4 ProjectionLH(float aspect, float fovy, float near, float far)
	{
		const float tanHalfFovy = tan(fovy / 2.0f);

		Matrix4x4 result;
		result.m[0 * 4 + 0] = 1.0f / (aspect * tanHalfFovy);
		result.m[1 * 4 + 1] = 1.0f / (tanHalfFovy);
		result.m[1 * 4 + 3] = 1.0f;

#		if GRAPHIC_DEPTH_CLIP_SPACE == GRAPHIC_DEPTH_ZERO_TO_ONE
		result.m[2 * 4 + 2] = far / (far - near);
		result.m[3 * 4 + 2] = -(far * near) / (far - near);
#		else
		result.m[2 * 4 + 2] = (far + near) / (far - near);
		result.m[3 * 4 + 2] = -(2.0f * far * near) / (far - near);
#		endif

		return Matrix4x4();
	}

	Matrix4x4 ProjectionRH(float aspect, float fovy, float near, float far)
	{
		const float tanHalfFovy = tan(fovy / 2.0f);

		Matrix4x4 result;
		result.m11 = result.m22 = result.m33 = result.m44 = 0.0f;
		result.m[0 * 4 + 0] = 1.0f / (aspect * tanHalfFovy);
		result.m[1 * 4 + 1] = 1.0f / (tanHalfFovy);
		result.m[2 * 4 + 3] = -1.0f;

#		if GRAPHIC_DEPTH_CLIP_SPACE == GRAPHIC_DEPTH_ZERO_TO_ONE
		result.m[2 * 4 + 2] = far / (near - far);
		result.m[3 * 4 + 2] = -(far * near) / (far - near);
#		else
		result.m[2 * 4 + 2] = -(far + near) / (far - near);
		result.m[3 * 4 + 2] = -(2.0f * far * near) / (far - near);
#		endif

		return result;
	}

	Matrix4x4 Ortho(float left, float right, float bottom, float top, float near, float far)
	{
#		if GRAPHIC_LEFT_HAND_SYSTEM
		return OrthoLH(left, right, bottom, top, near, far);
#		else
		return OrthoRH(left, right, bottom, top, near, far);
#		endif
	}

	Matrix4x4 OrthoLH(float left, float right, float bottom, float top, float near, float far)
	{
		Matrix4x4 Result;
		Result.m11 = 2.0f / (right - left);
		Result.m22 = 2.0f / (top - bottom);
		Result.m41 = -(right + left) / (right - left);
		Result.m42 = -(top + bottom) / (top - bottom);

#		if GRAPHIC_DEPTH_CLIP_SPACE == GRAPHIC_DEPTH_ZERO_TO_ONE
		Result.m33 = 1.0f / (far - near);
		Result.m43 = -near / (far - near);
#		else
		Result.m33 = 2.0f / (far - near);
		Result.m43 = -(far + near) / (far - near);
#		endif

		return Result;
	}

	Matrix4x4 OrthoRH(float left, float right, float bottom, float top, float near, float far)
	{
		Matrix4x4 Result;

		Result.m11 = 2.0f / (right - left);
		Result.m22 = 2.0f / (top - bottom);
		Result.m41 = -(right + left) / (right - left);
		Result.m42 = -(top + bottom) / (top - bottom);

#		if GRAPHIC_DEPTH_CLIP_SPACE == GRAPHIC_DEPTH_ZERO_TO_ONE
		Result[2][2] = -1.0f / (far - near);
		Result[3][2] = -near / (far - near);
#		else
		Result.m33 = -2.0f / (far - near);
		Result.m43 = -(far + near) / (far - near);
#		endif

		return Result;
	}

	Matrix4x4 Frustum(float left, float right, float bottom, float top, float nearVal, float farVal)
	{
#if GRAPHIC_LEFT_HAND_SYSTEM
		return FrustumLH(left, right, bottom, top, nearVal, farVal);
#elif GRAPHIC_RIGHT_HAND_SYSTEM 
		return FrustumRH(left, right, bottom, top, nearVal, farVal);
#endif
	}

	Matrix4x4 FrustumLH(float left, float right, float bottom, float top, float nearVal, float farVal)
	{
		//			tmat4x4<T, defaultp> Result(0);
		//			Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		//			Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		//			Result[2][0] = (right + left) / (right - left);
		//			Result[2][1] = (top + bottom) / (top - bottom);
		//			Result[2][3] = static_cast<T>(1);
		//
		//#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
		//			Result[2][2] = farVal / (farVal - nearVal);
		//			Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		//#		else
		//			Result[2][2] = (farVal + nearVal) / (farVal - nearVal);
		//			Result[3][2] = -(static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		//#		endif

		return Matrix4x4();
	}

	Matrix4x4 FrustumRH(float left, float right, float bottom, float top, float nearVal, float farVal)
	{

		//			tmat4x4<T, defaultp> Result(0);
		//			Result[0][0] = (static_cast<T>(2) * nearVal) / (right - left);
		//			Result[1][1] = (static_cast<T>(2) * nearVal) / (top - bottom);
		//			Result[2][0] = (right + left) / (right - left);
		//			Result[2][1] = (top + bottom) / (top - bottom);
		//			Result[2][3] = static_cast<T>(-1);
		//
		//#		if GLM_DEPTH_CLIP_SPACE == GLM_DEPTH_ZERO_TO_ONE
		//			Result[2][2] = farVal / (nearVal - farVal);
		//			Result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
		//#		else
		//			Result[2][2] = -(farVal + nearVal) / (farVal - nearVal);
		//			Result[3][2] = -(static_cast<T>(2) * farVal * nearVal) / (farVal - nearVal);
		//#		endif

		return Matrix4x4();
	}

	Matrix4x4 LookAt(Vector3 eye, Vector3 at, Vector3 up)
	{
#if GRAPHIC_LEFT_HAND_SYSTEM
		return LookAtLH(eye, at, up);
#elif GRAPHIC_RIGHT_HAND_SYSTEM 
		return LookAtRH(eye, at, up);
#endif
	}

	Matrix4x4 LookAtLH(Vector3 eye, Vector3 at, Vector3 up)
	{
		Vector3 f(Vector3::Normalize(at - eye));
		Vector3 s(Vector3::Normalize(Vector3::Cross(up, f)));
		Vector3 u(Vector3::Cross(f, s));

		Matrix4x4 result;
		result.m[0 * 4 + 0] = s.x;
		result.m[1 * 4 + 0] = s.y;
		result.m[2 * 4 + 0] = s.z;
		result.m[0 * 4 + 1] = u.x;
		result.m[1 * 4 + 1] = u.y;
		result.m[2 * 4 + 1] = u.z;
		result.m[0 * 4 + 2] = f.x;
		result.m[1 * 4 + 2] = f.y;
		result.m[2 * 4 + 2] = f.z;
		result.m[3 * 4 + 0] = -Vector3::Dot(s, eye);
		result.m[3 * 4 + 1] = -Vector3::Dot(u, eye);
		result.m[3 * 4 + 2] = Vector3::Dot(f, eye);

		return result;
	}

	Matrix4x4 LookAtRH(Vector3 eye, Vector3 at, Vector3 up)
	{
		Vector3 f(Vector3::Normalize(at - eye));
		Vector3 s(Vector3::Normalize(Vector3::Cross(f, up)));
		Vector3 u(Vector3::Cross(s, f));

		Matrix4x4 result;
		result.m[0 * 4 + 0] = s.x;
		result.m[1 * 4 + 0] = s.y;
		result.m[2 * 4 + 0] = s.z;
		result.m[0 * 4 + 1] = u.x;
		result.m[1 * 4 + 1] = u.y;
		result.m[2 * 4 + 1] = u.z;
		result.m[0 * 4 + 2] = -f.x;
		result.m[1 * 4 + 2] = -f.y;
		result.m[2 * 4 + 2] = -f.z;
		result.m[3 * 4 + 0] = -Vector3::Dot(s, eye);
		result.m[3 * 4 + 1] = -Vector3::Dot(u, eye);
		result.m[3 * 4 + 2] = Vector3::Dot(f, eye);

		return result;
	}

	Matrix4x4 Translate(Vector3 pos)
	{
		Matrix4x4 mat;
		mat.m41 = pos.x;
		mat.m42 = pos.y;
		mat.m43 = pos.z;
		return mat;
	}

	Matrix4x4 Scale(Vector3 scale)
	{
		Matrix4x4 mat;
		mat.m11 = scale.x;
		mat.m22 = scale.y;
		mat.m33 = scale.z;
		return mat;
	}

	Matrix4x4 Rotate(float AngleX, float AngleY, float AngleZ)
	{
		return Matrix4x4();
	}

	Matrix4x4 Rotate(Vector3 axis, float angle)
	{
		Quaternion q;
		q.rotateByAxis(Vector3(0, 1, 0), angle);
		return Quaternion::QuaternionToMatrix4x4(q);
	}

}