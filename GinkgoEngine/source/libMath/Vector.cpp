#include"Vector.h"
#include"Math.h"

namespace External
{

	Vector3::Vector3()
	{
		x = y = z = 0.0f;
	}

	Vector3::Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3::Vector3(const Vector3& src)
	{
		x = src.x;
		y = src.y;
		z = src.z;
	}

	Vector3 Vector3::Normalize(const Vector3& vec)
	{
		float magnitude = Vector3::Magnitude(vec);
		return Vector3(vec.x / magnitude, vec.y / magnitude, vec.z / magnitude);
	}

	float Vector3::Magnitude(const Vector3 & _vec)
	{
		return sqrt(_vec.x*_vec.x + _vec.y*_vec.y + _vec.z*_vec.z);
	}

	Vector3 Vector3::Reflect(const Vector3 & _r, const Vector3 & _n)
	{
		return Vector3();
	}

	Vector3 Vector3::Up()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	Vector3 Vector3::Right()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

	Vector3 Vector3::Forward()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::Zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	Vector3 Vector3::One()
	{
		return Vector3(1.0f, 1.0f, 1.0f);
	}

	float Vector3::AngelDegree(Vector3& from, Vector3& to)
	{
		return 0.0f;
	}

	float Vector3::AngelRadian(Vector3& from, Vector3& to)
	{
		return 0.0f;
	}

	Vector3 Vector3::Cross(Vector3& src, Vector3& dist)
	{
		float x, y, z;
		x = src.y*dist.z - dist.y*src.z;
		y = src.z*dist.x - dist.z*src.x;
		z = src.x*dist.y - dist.x*src.y;
		return Vector3(x, y, z);
	}

	float Vector3::Dot(const Vector3& a,const Vector3& b)
	{
		return a.x*b.x + a.y*b.y + a.z*b.z;
	}

	void Vector3::normalize()
	{
		float magnitude = this->magnitude();
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	float Vector3::magnitude()
	{
		return sqrt(x*x + y * y + z * z);
	}

	Vector3 Vector3::operator +(const Vector3& dist)
	{
		return Vector3(x + dist.x, y + dist.y, z + dist.z);
	}

	Vector3 Vector3::operator -(const Vector3& dist)
	{
		return Vector3(x - dist.x, y - dist.y, z - dist.z);
	}

	Vector3 Vector3::operator *(float k)
	{
		return Vector3(x*k, y*k, z*k);
	}

	Vector3 Vector3::operator *(const Vector3& dist)
	{
		return Vector3(x*dist.x, y*dist.y, z*dist.z);
	}

	Vector3 Vector3::operator /(float k)
	{
		return Vector3(x / k, y / k, z / k);
	}

	Vector3& Vector3::operator =(const Vector3& dist)
	{
		if (&dist == this)
			return *this;
		else
		{
			this->x = dist.x;
			this->y = dist.y;
			this->z = dist.z;
			return *this;
		}
	}

	Vector3 Vector3::operator *=(float k)
	{
		x *= k;
		y *= k;
		z *= k;
		return *this;
	}

	Vector3 Vector3::operator /=(float k)
	{
		x /= k;
		y /= k;
		z /= k;
		return *this;
	}

	Vector3 Vector3::operator +=(const Vector3& dist)
	{
		x += dist.x;
		y += dist.y;
		z += dist.z;
		return *this;
	}

	Vector3 Vector3::operator -=(const Vector3& dist)
	{
		x -= dist.x;
		y -= dist.y;
		z -= dist.z;
		return *this;
	}

	bool  Vector3::operator ==(const Vector3& dist)
	{
		return !(*this != dist);
	}

	bool  Vector3::operator !=(const Vector3& dist)
	{
		if (RobustCompareFloat(this->x, dist.x))
		{
			if (RobustCompareFloat(this->y, dist.y))
			{
				if (RobustCompareFloat(this->z, dist.z))
				{
					return true;
				}
			}
		}
		return false;
	}



	Vector4::Vector4()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}


	Vector4::Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4::Vector4(const Vector4 & src)
	{
		this->x = src.x;
		this->y = src.y;
		this->z = src.z;
		this->w = src.w;
	}

	void Vector4::normalize()
	{
		float magnitude = this->magnitude();
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	float Vector4::magnitude()
	{
		return sqrt(x*x + y * y + z * z);
	}

	Vector4 Vector4::operator+(const Vector4& dist)
	{
		return Vector4(x + dist.x, y + dist.y, z + dist.z, w);
	}

	Vector4 Vector4::operator-(const Vector4& dist)
	{
		return Vector4(x - dist.x, y - dist.y, z - dist.z, w);
	}

	Vector4 Vector4::operator*(float k)
	{
		return Vector4(x *k, y *k, z *k, w);
	}

	Vector4 Vector4::operator/(float k)
	{
		if (!k)
			return Vector4(POSITIVE_INFINITY, POSITIVE_INFINITY, POSITIVE_INFINITY, 0.0f);

		return Vector4(x / k, y / k, z / k, w);
	}

	Vector4 & Vector4::operator=(const Vector4 & dist)
	{
		if (&dist == this)
			return *this;
		else
		{
			this->x = dist.x;
			this->y = dist.y;
			this->z = dist.z;
			return *this;
		}
	}

	Vector4 Vector4::operator*=(float k)
	{
		x *= k;
		y *= k;
		z *= k;
		return *this;
	}

	Vector4 Vector4::operator/=(float k)
	{
		x /= k;
		y /= k;
		z /= k;
		return *this;
	}

	Vector4 Vector4::operator+=(const Vector4& dist)
	{
		x += dist.x;
		y += dist.y;
		z += dist.z;
		return *this;
	}

	Vector4 Vector4::operator-=(const Vector4& dist)
	{
		x -= dist.x;
		y -= dist.y;
		z -= dist.z;
		return *this;
	}

	bool Vector4::operator==(const Vector4& dist)
	{
		return !(*this != dist);
	}

	bool Vector4::operator!=(const Vector4& dist)
	{
		if (RobustCompareFloat(this->x, dist.x))
		{
			if (RobustCompareFloat(this->y, dist.y))
			{
				if (RobustCompareFloat(this->z, dist.z))
				{
					if (RobustCompareFloat(this->w, dist.w))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	Vector4 Vector4::Normalize(const Vector4& dist)
	{
		float magnitude = Vector4::Magnitude(dist);
		return Vector4(dist.x / magnitude, dist.y / magnitude, dist.z / magnitude);
	}

	float Vector4::Magnitude(const Vector4& _vec)
	{
		return sqrt(_vec.x*_vec.x + _vec.y*_vec.y + _vec.z*_vec.z);
	}

	Vector4 Vector4::Up()
	{
		return Vector4(0.0f, 1.0f, 0.0f);
	}

	Vector4 Vector4::Right()
	{
		return Vector4(0.0f, 0.0f, 1.0f);
	}

	Vector4 Vector4::Forward()
	{
		return Vector4(1.0f, 0.0f, 0.0f);
	}

	Vector4 Vector4::Zero()
	{
		return Vector4(0.0f, 0.0f, 0.0f);
	}

	Vector4 Vector4::One()
	{
		return Vector4(1.0f, 1.0f, 1.0f);
	}

	float Vector4::AngelDegree(Vector4& from, Vector4& to)
	{
		return 0.0f;
	}

	float Vector4::AngelRadian(Vector4& from, Vector4& to)
	{
		return 0.0f;
	}

	Vector4 Vector4::Mul(Vector4& a, Vector4& b)
	{
		return Vector4();
	}

	float Vector4::Dot(Vector4& a, Vector4& b)
	{
		return 0.0f;
	}

	Vector2::Vector2()
	{
		x = y = 0.0f;
	}

	Vector2::Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2::Vector2(const Vector2 & vec)
	{
		x = vec.x;
		y = vec.y;
	}

	Vector2::~Vector2()
	{
	}

	Vector2 Vector2::Zero()
	{
		return Vector2();
	}

	Vector2 Vector2::One()
	{
		return Vector2(1.0f, 1.0f);
	}

	Vector2 Vector2::Normalize(const Vector2 & _vec)
	{
		float magnitude = Vector2::Magnitude(_vec);
		return Vector2(_vec.x / magnitude, _vec.y / magnitude);
	}

	float Vector2::Magnitude(const Vector2& _vec)
	{
		return sqrt(_vec.x*_vec.x + _vec.y*_vec.y);
	}

	void Vector2::normalize()
	{
		float magnitude = this->magnitude();
		this->x /= magnitude;
		this->y /= magnitude;
	}

	float Vector2::magnitude()
	{
		return sqrt(x * x + y * y);
	}

	Vector2 Vector2::operator+(const Vector2 & dist)
	{
		return Vector2(this->x + dist.x, this->y + dist.y);
	}

	Vector2 Vector2::operator-(const Vector2 & dist)
	{
		return Vector2(this->x - dist.x, this->y - dist.y);
	}

	Vector2 Vector2::operator*(float k)
	{
		return Vector2(this->x *k, this->y*k);
	}

	Vector2 Vector2::operator/(float k)
	{
		return Vector2(this->x / k, this->y / k);
	}

	Vector2 & Vector2::operator=(const Vector2 & dist)
	{
		if (&dist == this)
			return *this;
		else
		{
			this->x = dist.x;
			this->y = dist.y;
			return *this;
		}
	}

	Vector2 Vector2::operator*=(float k)
	{
		x *= k;
		y *= k;
		return *this;
	}

	Vector2 Vector2::operator/=(float k)
	{
		x /= k;
		y /= k;
		return *this;
	}

	Vector2 Vector2::operator+=(const Vector2 & dist)
	{
		x += dist.x;
		y += dist.y;
		return *this;
	}

	Vector2 Vector2::operator-=(const Vector2 & dist)
	{
		x -= dist.x;
		y -= dist.y;
		return *this;
	}

	bool Vector2::operator==(const Vector2 & dist)
	{
		return !(*this != dist);
	}

	bool Vector2::operator!=(const Vector2 & dist)
	{
		if (RobustCompareFloat(this->x, dist.x))
		{
			if (RobustCompareFloat(this->y, dist.y))
			{
				return true;
			}
		}
		return false;
	}


}
