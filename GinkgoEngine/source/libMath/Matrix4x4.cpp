#include"Math.h"
#include"Vector.h"

#include "Matrix4x4.h"


namespace External
{

	Vector4 Matrix4x4::MultiplyVector(const Vector4 & vector, const Matrix4x4 & mat)
	{
		Vector4 *v = new Vector4();
		v->x += vector.x*mat.m11 + vector.y*mat.m21 + vector.z*mat.m31 + vector.w*mat.m41;
		v->y += vector.x*mat.m12 + vector.y*mat.m22 + vector.z*mat.m32 + vector.w*mat.m42;
		v->z += vector.x*mat.m13 + vector.y*mat.m23 + vector.z*mat.m33 + vector.w*mat.m43;
		v->w += vector.x*mat.m14 + vector.y*mat.m24 + vector.z*mat.m34 + vector.w*mat.m44;

		return *v;
	}

	Matrix4x4 Matrix4x4::MultiplyMatrix(const Matrix4x4 & mat1, const Matrix4x4 & mat2)
	{
		Matrix4x4 Result;
		Vector4 SrcA0 = mat1.v1;
		Vector4 SrcA1 = mat1.v2;
		Vector4 SrcA2 = mat1.v3;
		Vector4 SrcA3 = mat1.v4;

		Vector4 SrcB0 = mat2.v1;
		Vector4 SrcB1 = mat2.v2;
		Vector4 SrcB2 = mat2.v3;
		Vector4 SrcB3 = mat2.v4;

		Result.v1 = SrcA0 * SrcB0.x + SrcA1 * SrcB0.y + SrcA2 * SrcB0.z + SrcA3 * SrcB0.w;
		Result.v2 = SrcA0 * SrcB1.x + SrcA1 * SrcB1.y + SrcA2 * SrcB1.z + SrcA3 * SrcB1.w;
		Result.v3 = SrcA0 * SrcB2.x + SrcA1 * SrcB2.y + SrcA2 * SrcB2.z + SrcA3 * SrcB2.w;
		Result.v4 = SrcA0 * SrcB3.x + SrcA1 * SrcB3.y + SrcA2 * SrcB3.z + SrcA3 * SrcB3.w;
		return Result;
	}

	Matrix4x4 Matrix4x4::IdentityMatrix()
	{
		return Matrix4x4();
	}

	Matrix4x4 Matrix4x4::InverseMatrix(Matrix4x4 & mat)
	{
		return Matrix4x4();
	}

	Matrix4x4 Matrix4x4::TransposeMatrix(Matrix4x4 & mat)
	{
		Vector4 v0, v1, v2, v3;
		v0.x = mat.v1.x;
		v0.y = mat.v2.x;
		v0.z = mat.v3.x;
		v0.w = mat.v4.x;

		v1.x = mat.v1.y;
		v1.y = mat.v2.y;
		v1.z = mat.v3.y;
		v1.w = mat.v4.y;

		v2.x = mat.v1.z;
		v2.y = mat.v2.z;
		v2.z = mat.v3.z;
		v2.w = mat.v4.z;

		v3.x = mat.v1.w;
		v3.y = mat.v2.w;
		v3.z = mat.v3.w;
		v3.w = mat.v4.w;

		Matrix4x4 result;
		result.v1 = v0;
		result.v2 = v1;
		result.v3 = v2;
		result.v4 = v3;

		return result;
	}

	float Matrix4x4::Deteminant(Matrix4x4 mat)
	{
		float det = mat.m11*mat.m22*mat.m33 + mat.m21*mat.m32*mat.m13 + mat.m12*mat.m23*mat.m31;
		det -= mat.m13*mat.m22 * mat.m31 + mat.m12*mat.m21*mat.m33 + mat.m23*mat.m32*mat.m11;
		return det;
	}

	Matrix4x4::Matrix4x4()
	{
		m11 = m22 = m33 = m44 = 1;
		m12 = m13 = m14 = 0;
		m21 = m23 = m24 = 0;
		m32 = m31 = m34 = 0;
		m41 = m42 = m43 = 0;

	}

	Matrix4x4::Matrix4x4(Vector3& line1, Vector3& line2, Vector3& line3)
	{
		v1.x = line1.x;
		v1.y = line1.y;
		v1.z = line1.z;
		v1.w = 0.0f;

		v2.x = line2.x;
		v2.y = line2.y;
		v2.z = line2.z;
		v2.w = 0.0f;

		v3.x = line3.x;
		v3.y = line3.y;
		v3.z = line3.z;
		v3.w = 0.0f;

		v4.x = 0.0f;
		v4.y = 0.0f;
		v4.z = 0.0f;
		v4.w = 1.0f;

	}

	Matrix4x4::Matrix4x4(Vector4 & line1, Vector4 & line2, Vector4 & line3, Vector4 & line4)
	{
		v1 = line1;
		v2 = line2;
		v3 = line3;
		v4 = line4;
	}

	Matrix4x4::Matrix4x4(const Matrix4x4 & Mat)
	{
		m11 = Mat.m11;
		m12 = Mat.m12;
		m13 = Mat.m13;
		m14 = Mat.m14;

		m21 = Mat.m21;
		m22 = Mat.m22;
		m23 = Mat.m23;
		m24 = Mat.m24;

		m31 = Mat.m31;
		m32 = Mat.m32;
		m33 = Mat.m33;
		m34 = Mat.m34;

		m41 = Mat.m41;
		m42 = Mat.m42;
		m43 = Mat.m43;
		m44 = Mat.m44;
	}

	float Matrix4x4::determinant()
	{
		float det = m11 * m22*m33 + m21 * m32*m13 + m12 * m23*m31;
		det -= m13 * m22 * 31 + m12 * m21*m33 + m23 * m32*m11;
		return det;
	}

	Matrix4x4 Matrix4x4::operator+(Matrix4x4 dist)
	{
		m11 += dist.m11;
		m12 += dist.m12;
		m13 += dist.m13;
		m14 += dist.m14;

		m21 += dist.m21;
		m22 += dist.m22;
		m23 += dist.m23;
		m24 += dist.m24;

		m31 += dist.m31;
		m32 += dist.m32;
		m33 += dist.m33;
		m34 += dist.m34;

		m41 += dist.m41;
		m42 += dist.m42;
		m43 += dist.m43;
		m44 += dist.m44;

		return *this;
	}

	Matrix4x4 Matrix4x4::operator-(Matrix4x4 dist)
	{
		m11 -= dist.m11;
		m12 -= dist.m12;
		m13 -= dist.m13;
		m14 -= dist.m14;

		m21 -= dist.m21;
		m22 -= dist.m22;
		m23 -= dist.m23;
		m24 -= dist.m24;

		m31 -= dist.m31;
		m32 -= dist.m32;
		m33 -= dist.m33;
		m34 -= dist.m34;

		m41 -= dist.m41;
		m42 -= dist.m42;
		m43 -= dist.m43;
		m44 -= dist.m44;

		return *this;
	}

	Matrix4x4 Matrix4x4::operator*(float k)
	{
		m11 *= k;
		m12 *= k;
		m13 *= k;
		m14 *= k;

		m21 *= k;
		m22 *= k;
		m23 *= k;
		m24 *= k;

		m31 *= k;
		m32 *= k;
		m33 *= k;
		m34 *= k;

		m41 *= k;
		m42 *= k;
		m43 *= k;
		m44 *= k;

		return *this;
	}

	Matrix4x4 Matrix4x4::operator/(float k)
	{
		if (!k)
			return Matrix4x4();

		m11 /= k;
		m12 /= k;
		m13 /= k;
		m14 /= k;

		m21 /= k;
		m22 /= k;
		m23 /= k;
		m24 /= k;

		m31 /= k;
		m32 /= k;
		m33 /= k;
		m34 /= k;

		m41 /= k;
		m42 /= k;
		m43 /= k;
		m44 /= k;

		return *this;
	}

	Matrix4x4 & Matrix4x4::operator=(const Matrix4x4 & dist)
	{
		if (&dist == this)
			return *this;
		else
		{
			m11 = dist.m11;
			m12 = dist.m12;
			m13 = dist.m13;
			m14 = dist.m14;

			m21 = dist.m21;
			m22 = dist.m22;
			m23 = dist.m23;
			m24 = dist.m24;

			m31 = dist.m31;
			m32 = dist.m32;
			m33 = dist.m33;
			m34 = dist.m34;

			m41 = dist.m41;
			m42 = dist.m42;
			m43 = dist.m43;
			m44 = dist.m44;
			return *this;
		}
	}

	Matrix4x4 Matrix4x4::operator*=(float k)
	{
		for (int i = 0; i < 16; i++)
		{
			this->m[i] *= k;
		}
		return *this;
	}

	Matrix4x4 Matrix4x4::operator/=(float k)
	{
		for (int i = 0; i < 16; i++)
		{
			this->m[i] /= k;
		}
		return *this;
	}

	Matrix4x4 Matrix4x4::operator +=(Matrix4x4 dist)
	{
		for (int i = 0; i < 16; i++)
		{
			this->m[i] += dist.m[i];
		}
		return *this;
	}

	Matrix4x4 Matrix4x4::operator -=(Matrix4x4 dist)
	{
		for (int i = 0; i < 16; i++)
		{
			this->m[i] -= dist.m[i];
		}
		return *this;
	}

	bool Matrix4x4::operator==(Matrix4x4 dist)
	{
		return !(*this != dist);
	}

	bool Matrix4x4::operator!=(const Matrix4x4& dist)
	{
		for (int i = 0; i < 16; i++)
		{
			if (this->m[i] != dist.m[i])
			{
				return true;
			}
		}
		return false;
	}

}