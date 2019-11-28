#pragma once

namespace External
{
	struct Vector2;
	struct Vector3;
	struct Vector4;

	struct Vector2
	{
	public:
		Vector2();
		Vector2(float x, float y);
		Vector2(const Vector2& vec);
		~Vector2();

	public:
		static Vector2 Zero();
		static Vector2 One();
		static Vector2 Normalize(const Vector2& _vec);
		static float Magnitude(const Vector2& _vec);

	public:
		void normalize();
		float magnitude();

	public:
		Vector2 operator +(const Vector2& dist);
		Vector2 operator -(const Vector2& dist);
		Vector2 operator *(float k);
		Vector2 operator /(float k);
		Vector2& operator =(const Vector2& dist);
		Vector2 operator *=(float k);
		Vector2 operator /=(float k);
		Vector2 operator +=(const Vector2& dist);
		Vector2 operator -=(const Vector2& dist);
		bool  operator ==(const Vector2& dist);
		bool  operator !=(const Vector2& dist);

	public:
		float x, y;

	};

	struct Vector3
	{
	public:
		static Vector3 Up();
		static Vector3 Right();
		static Vector3 Forward();
		static Vector3 Zero();
		static Vector3 One();
		static float AngelDegree(Vector3& from, Vector3& to);
		static float AngelRadian(Vector3& from, Vector3& to);
		static Vector3 Cross(Vector3& a, Vector3& b);
		static float Dot(const Vector3& a,const Vector3& b);
		static Vector3 Normalize(const Vector3& _vec);
		static float Magnitude(const Vector3& _vec);
		static Vector3 Reflect(const Vector3& _r, const Vector3& _n);

	public:
		Vector3();
		Vector3(float x, float y = 0, float z = 0);
		Vector3(const Vector3& vec);

	public:
		void normalize();
		float magnitude();

	public:
		Vector3 operator +(const Vector3& dist);
		Vector3 operator -(const Vector3& dist);
		Vector3 operator *(float k);
		Vector3 operator *(const Vector3& dist);
		Vector3 operator /(float k);
		Vector3& operator =(const Vector3& dist);
		Vector3 operator *=(float k);
		Vector3 operator /=(float k);
		Vector3 operator +=(const Vector3& dist);
		Vector3 operator -=(const Vector3& dist);
		bool  operator ==(const Vector3& dist);
		bool  operator !=(const Vector3& dist);

	//public:
		//inline vec3 operator+(const vec3 &v2) { return vec3(this->x + v2.x, this->y + v2.y, this->z + v2.z); }
		//inline vec3 operator+(const float v) { return vec3(this->x + v, this->y + v, this->z + v); }
		//inline vec3 operator-(const vec3 &v2) { return vec3(this->x - v2.x, this->y - v2.y, this->z - v2.z); }
		//inline vec3 operator*(const float t) { return vec3(this->x * t, this->y * t, this->z * t); }
		//inline vec3 operator*(const vec3 &v2) { return vec3(this->x * v2.x, this->y * v2.y, this->z * v2.z); }
		//inline vec3 operator/(const float t) { return vec3(this->x / t, this->y / t, this->z / t); }
		//inline vec3& operator+=(const vec3 &v2) { this->x += v2.x; this->y += v2.y; this->z += v2.z;  return *this; }
		//inline vec3& operator-=(const vec3 &v2) { this->x -= v2.x; this->y -= v2.y; this->z -= v2.z;  return *this; }
		//inline vec3& operator*=(const vec3 &v2) { this->x *= v2.x; this->y *= v2.y; this->z *= v2.z;  return *this; }
		//inline vec3& operator/=(const vec3 &v2) { this->x /= v2.x; this->y /= v2.y; this->z /= v2.z;  return *this; }
		//inline vec3& operator*=(const float t) { this->x *= t; this->y *= t; this->z *= t;  return *this; }
		//inline vec3& operator/=(const float t) { this->x /= t; this->y /= t; this->z /= t;  return *this; }

		inline float operator[](int i) { return a[i]; }

	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float a[3];
		};

	};

	struct Vector4
	{
	public:
		static Vector4 Up();
		static Vector4 Right();
		static Vector4 Forward();
		static Vector4 Zero();
		static Vector4 One();
		static float AngelDegree(Vector4& from, Vector4& to);
		static float AngelRadian(Vector4& from, Vector4& to);
		static Vector4 Mul(Vector4& a, Vector4& b);
		static float Dot(Vector4& a, Vector4& b);
		static Vector4 Normalize(const Vector4& _vec);
		static float Magnitude(const Vector4& _vec);

	public:
		Vector4();
		Vector4(float x, float y = 0, float z = 0, float w = 1);
		Vector4(const Vector4& src);

	public:
		void normalize();
		float magnitude();

	public:
		Vector4 operator +(const Vector4& dist);
		Vector4 operator -(const Vector4& dist);
		Vector4 operator *(float k);
		Vector4 operator /(float k);
		Vector4& operator =(const Vector4& dist);
		Vector4 operator *=(float k);
		Vector4 operator /=(float k);
		Vector4 operator +=(const Vector4& dist);
		Vector4 operator -=(const Vector4& dist);
		bool  operator ==(const Vector4& dist);
		bool  operator !=(const Vector4& dist);

	public:
		float x, y, z, w;

	};

}


