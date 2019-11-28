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
				//float mem1;//�ڴ�ռλ������ͬ��ʸ��v1��magtitude����
				float m21, m22, m23, m24;
				//float mem2;//�ڴ�ռλ������ͬ��ʸ��v2��magtitude����
				float m31, m32, m33, m34;
				//float mem3;//�ڴ�ռλ������ͬ��ʸ��v3��magtitude����
				float m41, m42, m43, m44;
				//float mem4;//�ڴ�ռλ������ͬ��ʸ��v4��magtitude����
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
		static Matrix4x4 IdentityMatrix();//��λ����
		static Matrix4x4 InverseMatrix(Matrix4x4 &mat);//�����
		static Matrix4x4 TransposeMatrix(Matrix4x4& mat);//ת�þ���
		static float Deteminant(Matrix4x4 mat); //��������ʽ��ֵ

	public:
		static Matrix4x4 identity;

	};


}

