#pragma once

namespace External
{
	struct Vector;

	struct Matrix4x4
	{
	public:
		Matrix4x4();
		Matrix4x4(Vector3& line1, Vector3& line2, Vector3& line3);
		Matrix4x4(Vector4& line1, Vector4& line2, Vector4& line3, Vector4& line4);
		Matrix4x4(const Matrix4x4& Mat);

	public:
		float determinant();

	public:
		Matrix4x4 operator +(Matrix4x4 dist);
		Matrix4x4 operator -(Matrix4x4 dist);
		Matrix4x4 operator *(float k);
		//Matrix4x4 operator *(Matrix4x4 dist);
		Matrix4x4 operator /(float k);
		Matrix4x4& operator =(const Matrix4x4& dist);
		Matrix4x4 operator *=(float k);
		Matrix4x4 operator /=(float k);
		Matrix4x4 operator +=(Matrix4x4 dist);
		Matrix4x4 operator -=(Matrix4x4 dist);
		bool  operator ==(Matrix4x4 dist);
		bool  operator !=(const Matrix4x4& dist);

	public:
		union
		{
			struct
			{
				float m11, m12, m13, m14;
				//float mem1;//内存占位符，等同于矢量v1的magtitude属性
				float m21, m22, m23, m24;
				//float mem2;//内存占位符，等同于矢量v2的magtitude属性
				float m31, m32, m33, m34;
				//float mem3;//内存占位符，等同于矢量v3的magtitude属性
				float m41, m42, m43, m44;
				//float mem4;//内存占位符，等同于矢量v4的magtitude属性
			};
			struct
			{
				Vector4 v1;
				Vector4 v2;
				Vector4 v3;
				Vector4 v4;
			};
			float m[16];
		};

	public:
		static Vector4 MultiplyVector(const Vector4& vector, const Matrix4x4& mat);
		static Matrix4x4 MultiplyMatrix(const Matrix4x4& mat1, const Matrix4x4& mat2);
		static Matrix4x4 IdentityMatrix();//单位矩阵
		static Matrix4x4 InverseMatrix(Matrix4x4 &mat);//逆矩阵
		static Matrix4x4 TransposeMatrix(Matrix4x4& mat);//转置矩阵
		static float Deteminant(Matrix4x4 mat); //计算行列式的值

	public:
		static Matrix4x4 identity;

	};


}

