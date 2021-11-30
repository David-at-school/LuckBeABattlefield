#pragma once
#include <cmath>
#include <iostream>

namespace luck
{
	struct Vector2
	{
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x) : x{ x }, y{ x } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(int x, int y) : x{ static_cast<float>(x) }, y{ static_cast<float>(y) } {}

		float operator [] (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }

		void Set(float x, float y) { this->x = x, this->y = y; }

		Vector2 operator + (const Vector2& v) const { return { x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return { x - v.x, y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return { x * v.x, y * v.y }; }
		Vector2 operator / (const Vector2& v) const { return { x / v.x, y / v.y }; }

		Vector2 operator + (float s) const { return { x + s, y + s }; }
		Vector2 operator - (float s) const { return { x - s, y - s }; }
		Vector2 operator * (float s) const { return { x * s, y * s }; }
		Vector2 operator / (float s) const { return { x / s, y / s }; }

		Vector2& operator += (const Vector2& v) { x += v.x, y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x, y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x, y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x, y /= v.y; return *this; }

		Vector2& operator += (float s) { x += s, y += s; return *this; }
		Vector2& operator -= (float s) { x -= s, y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s, y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s, y /= s; return *this; }

		Vector2 operator - () const { return { -x, -y }; }

		bool operator == (const Vector2& v) const { return x == v.x && y == v.y; }
		bool operator != (const Vector2& v) const { return x != v.x || y != v.y; }

		float Length() const;
		float LengthSqr() const;

		Vector2 Normalized() const;
		void Normalize();

		float Angle() const;

		static float Distance(const Vector2& v1, const Vector2& v2);
		static Vector2 Rotate(const Vector2& v, float radians);
		static float Angle(const Vector2& v1, const Vector2& v2);
		static float SignedAngle(const Vector2& v1, const Vector2& v2);
		static float Dot(const Vector2& v1, const Vector2& v2);

		friend std::istream& operator >> (std::istream& stream, Vector2& v);
		friend std::ostream& operator << (std::ostream& stream, Vector2& v);

		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
		static const Vector2 one;
		static const Vector2 zero;

	};

	inline float Vector2::Length() const
	{
		return std::sqrt(x * x + y * y);
	}

	inline float Vector2::LengthSqr() const
	{
		return (x * x + y * y);
	}

	inline Vector2 Vector2::Normalized() const
	{
		return (Length() != 0) ? *this / Length() : Vector2::zero;
	}

	inline void Vector2::Normalize()
	{
		*this /= Length();
	}

	inline float Vector2::Angle() const
	{
		return std::atan2(y, x);
	}

	inline float Vector2::Distance(const Vector2& v1, const Vector2& v2)
	{
		return (v1 - v2).Length();
	}

	inline Vector2 Vector2::Rotate(const Vector2& v, float radians)
	{
		float x = v.x * std::cos(radians) - v.y * std::sin(radians);
		float y = v.x * std::sin(radians) + v.y * std::cos(radians);

		return { x, y };
	}

	inline float Vector2::SignedAngle(const Vector2& v1, const Vector2& v2)
	{
		float y = v1.x * v2.y - v1.y * v2.x;
		float x = v1.x * v2.x + v1.y * v2.y;
		return std::atan2(y, x);
	}
	
	inline float Vector2::Angle(const Vector2& v1, const Vector2& v2)
	{
		return std::acos(Dot(v1, v2));
	}

	inline float Vector2::Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}
}