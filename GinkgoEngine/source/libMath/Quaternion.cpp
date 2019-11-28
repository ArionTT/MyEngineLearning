#include"Math.h"
#include"Vector.h"
#include"Matrix4x4.h"

#include "Quaternion.h"


namespace External
{


	Quaternion::Quaternion()
	{
		w = 1.0f;
		x = y = z = 0.0f;
	}

	Quaternion::Quaternion(float x, float y, float z, float w)
	{
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Quaternion::Quaternion(const Quaternion & quaternion)
	{
		x = quaternion.x;
		y = quaternion.y;
		z = quaternion.z;
		w = quaternion.w;
	}


	Quaternion::~Quaternion()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	void Quaternion::normalize()
	{
		float mag = sqrt(w*w + x * x + y * y + z * z);
		if (mag > 0.0f)
		{
			float inv_mag = 1.0f / mag;
			x *= inv_mag;
			y *= inv_mag;
			z *= inv_mag;
			w *= inv_mag;
		}
		else
		{
			x = y = z = 0.0f;
			w = 1.0f;
		}
	}

	Vector3 Quaternion::getAxis() const
	{
		// sin^2(theta/2)  w=cos(theta/2)  ,sin^2(x)+cos^2(x)=1
		float sinThetaOver2Sq = 1.0f - w * w;

		if (sinThetaOver2Sq <= 0.0f)
		{
			return Vector3(1.0f, 0.0f, 0.0f);
		}

		//计算 1/sin(theta/2)
		float oneOverSinThetaOver2 = 1.0f / sqrt(sinThetaOver2Sq);

		//返回旋转轴
		return Vector3(x*oneOverSinThetaOver2, y*oneOverSinThetaOver2, z*oneOverSinThetaOver2);
	}

	float Quaternion::getAngle() const
	{
		float thetaOver2 = acos(w);

		return thetaOver2 * 2.0f;
	}

	void Quaternion::rotateByAxis(const Vector3 & axis, float theta)
	{
		Vector3 normalizedAxis = Vector3::Normalize(axis);

		float thetaOver2 = theta * 0.5f;
		float sinThetaOver2 = sin(thetaOver2);

		x = axis.x*sinThetaOver2;
		y = axis.y*sinThetaOver2;
		z = axis.z*sinThetaOver2;
		w = cos(thetaOver2);
	}

	void Quaternion::rotateX(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		w = cos(thetaOver2);
		x = sin(thetaOver2);
		y = 0.0f;
		z = 0.0f;
	}

	void Quaternion::rotateY(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		w = cos(thetaOver2);
		x = 0.0f;
		y = sin(thetaOver2);
		z = 0.0f;
	}

	void Quaternion::rotateZ(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		w = cos(thetaOver2);
		x = 0.0f;
		y = 0.0f;
		z = sin(thetaOver2);

	}

	Quaternion Quaternion::operator*(const Quaternion & q)
	{
		Quaternion result;

		result.w = w * q.w - x * q.x - y * q.y - z * q.z;
		result.x = w * q.x + x * q.w + z * q.y - y * q.z;
		result.y = w * q.y + y * q.w + x * q.z - z * q.x;
		result.z = w * q.z + z * q.w + y * q.x - x * q.y;

		return result;
	}

	Quaternion & Quaternion::operator*=(const Quaternion & q)
	{
		*this = *this*q;

		return *this;
	}

	float Quaternion::Dot(const Quaternion & a, const Quaternion & b)
	{
		return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
	}

	Quaternion Quaternion::Pow(const Quaternion & q, float exp)
	{
		if (abs(q.w) > 0.9999f)
		{
			return q;
		}

		//提取半角alpha
		float alph = acos(q.w);

		//计算新的alph
		float newalph = alph * exp;

		//计算新的w
		Quaternion result;
		result.w = cos(newalph);

		//计算新的xyz值
		float mult = sin(newalph) / sin(alph);
		result.x = q.x*mult;
		result.y = q.y*mult;
		result.z = q.z*mult;

		return result;
	}

	Matrix4x4 Quaternion::QuaternionToMatrix4x4(const Quaternion & q)
	{
		Vector3 line0(2.0f*(q.x*q.x + q.w*q.w) - 1.0f, 2.0f * (q.x*q.y + q.z*q.w), 2.0f * (q.x*q.z - q.y*q.w));
		Vector3 line1(2.0f*(q.x*q.y - q.z*q.w), 2.0f*(q.y*q.y + q.w*q.w) - 1.0f, 2.0f * (q.y*q.z + q.x*q.w));
		Vector3 line2(2.0f*(q.x*q.z + q.y*q.w), 2.0f * (q.z*q.y - q.x*q.w), 2.0f*(q.z*q.z + q.w*q.w) - 1.0f);
		//Vector3 line3(0, 0, 0);
		return Matrix4x4(line0, line1, line2);
	}

	Quaternion Quaternion::RotateByAngle(const Vector3& axis, float theta)
	{
		Vector3 normalizedAxis = Vector3::Normalize(axis);

		float thetaOver2 = theta * 0.5f;
		float sinThetaOver2 = sin(thetaOver2);

		float x = axis.x*sinThetaOver2;
		float y = axis.y*sinThetaOver2;
		float z = axis.z*sinThetaOver2;
		float w = cos(thetaOver2);

		return Quaternion(x, y, z, w);
	}

	Quaternion Quaternion::RotateX(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		float w = cos(thetaOver2);
		float x = sin(thetaOver2);
		float y = 0.0f;
		float z = 0.0f;

		return Quaternion(x, y, z, w);
	}

	Quaternion Quaternion::RotateY(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		float w = cos(thetaOver2);
		float x = 0.0f;
		float y = sin(thetaOver2);
		float z = 0.0f;

		return Quaternion(x, y, z, w);
	}

	Quaternion Quaternion::RotateZ(float theta)
	{
		float thetaOver2 = theta * 0.5f;

		float w = cos(thetaOver2);
		float x = 0.0f;
		float y = 0.0f;
		float z = sin(thetaOver2);

		return Quaternion(x, y, z, w);
	}

	Quaternion Quaternion::Identity()
	{
		return Quaternion();
	}

	Quaternion Quaternion::Conjugate(Quaternion quaternion)
	{
		float x = -quaternion.x;
		float y = -quaternion.y;
		float z = -quaternion.z;
		float w = quaternion.w;
		return Quaternion(x, y, z, w);
	}

	Quaternion Quaternion::Normalize(Quaternion quaternion)
	{
		float mag = sqrt(quaternion.w*quaternion.w + quaternion.x*quaternion.x + quaternion.y*quaternion.y + quaternion.z*quaternion.z);
		if (mag > 0.0f)
		{
			float inv_mag = 1.0f / mag;
			quaternion.x *= inv_mag;
			quaternion.y *= inv_mag;
			quaternion.z *= inv_mag;
			quaternion.w *= inv_mag;

			return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
		}
		else
		{
			return Quaternion::Identity();
		}
	}

	Quaternion Quaternion::Slerp(const Quaternion & a, const Quaternion & b, float t)
	{
		//检查出界，返回界值
		if (t <= 0.0f)return a;
		if (t >= 1.0f)return b;

		//用点乘计算夹角
		float cosOmega = Dot(a, b);

		return Quaternion();
	}

}

