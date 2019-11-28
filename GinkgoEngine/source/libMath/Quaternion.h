#pragma once

namespace External
{
	struct Vector3;
	struct Matrix4x4;
	struct Vector4;

	struct Quaternion
	{

	public:
		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Quaternion& quaternion);
		~Quaternion();

	public:
		//��λ��
		void normalize();
		//��ȡ��ת������
		Vector3 getAxis() const;
		//��ȡ��ת�Ƕ�
		float getAngle() const;
		//������Ԫ��
		void rotateByAxis(const Vector3& axis, float theta);
		//��X����ת
		void rotateX(float theta);
		//��Y����ת
		void rotateY(float theta);
		//��Z����ת
		void rotateZ(float theta);

	public:
		//��Ԫ�����
		Quaternion operator*(const Quaternion& q);
		Quaternion& operator *=(const Quaternion& q);

	public:
		float x, y, z;
		float w;

	public:
		//ͨ����ת�����ת�Ƕȹ�����ת��Ԫ��
		static Quaternion RotateByAngle(const Vector3& axis, float theta);
		//��X����ת
		static Quaternion RotateX(float theta);
		//��Y����ת
		static Quaternion RotateY(float theta);
		//��Z����ת
		static Quaternion RotateZ(float theta);
		//��λ��Ԫ��
		static Quaternion Identity();
		//������Ԫ��
		static Quaternion Conjugate(Quaternion quaternion);
		//�������Բ�ֵ
		static Quaternion Slerp(const Quaternion& a, const Quaternion & b, float t);
		//��Ԫ����λ��
		static Quaternion Normalize(Quaternion quaternion);
		//��Ԫ�����
		static float Dot(const Quaternion& a, const Quaternion& b);
		//��Ԫ����
		static Quaternion Pow(const Quaternion& q, float exp);
		//������Ԫ��
		static Quaternion Matrix4x4ToQuaternion(const Matrix4x4& mat);
		//ŷ���ǵ���Ԫ��
		static Quaternion EulerToQuaternion(const Vector4& euler);
		//��Ԫ��������
		static Matrix4x4  QuaternionToMatrix4x4(const Quaternion& q);
		//��Ԫ����ŷ����
		static Vector4  QuaternionToEuler(const Quaternion& q);


	};

}


