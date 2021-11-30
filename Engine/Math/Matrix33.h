#pragma once
#include "Vector2.h"

namespace luck
{
	struct Matrix33
	{
		float m[3][3]; // [column][row]

		Matrix33();

		void Scale(float s);
		void Scale(float sx, float sy);
		void Scale(const Vector2& s);
		Vector2 GetScale();

		void Rotate(float angle);
		float GetRotation();

		void Translate(const Vector2& v);
		Vector2 GetTranslate();

		void Identity();

		Matrix33 operator * (const Matrix33& mx) const;
		Vector2 operator * (const Vector2& v) const;
	};

	inline Matrix33::Matrix33()
	{
		m[0][0] = 0; m[1][0] = 0; m[2][0] = 0;
		m[0][1] = 0; m[1][1] = 0; m[2][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 0;
	}

	inline void Matrix33::Scale(float s)
	{
		m[0][0] = s; m[1][0] = 0; m[2][0] = 0;
		m[0][1] = 0; m[1][1] = s; m[2][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
	}

	inline void Matrix33::Scale(float sx, float sy)
	{
		m[0][0] = sx; m[1][0] = 0; m[2][0] = 0;
		m[0][1] = 0; m[1][1] = sy; m[2][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
	}

	inline void Matrix33::Scale(const Vector2& s)
	{
		m[0][0] = s.x; m[1][0] = 0; m[2][0] = 0;
		m[0][1] = 0; m[1][1] = s.y; m[2][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
	}

	inline Vector2 Matrix33::GetScale()
	{
		return Vector2{ m[0][0], m[1][1] };
	}

	inline void Matrix33::Rotate(float angle)
	{
		m[0][0] = std::cos(angle);	m[1][0] = std::sin(angle); m[2][0] = 0;
		m[0][1] = -std::sin(angle); m[1][1] = std::cos(angle); m[2][1] = 0;
		m[0][2] = 0;				m[1][2] = 0;				m[2][2] = 1;
	}

	inline float Matrix33::GetRotation()
	{
		float x = m[0][0];
		float y = m[1][0];

		return std::atan2(y, x);
	}

	inline void Matrix33::Translate(const Vector2& v)
	{
		m[0][0] = 1;	m[1][0] = 0;	m[2][0] = 0;
		m[0][1] = 0;	m[1][1] = 1;	m[2][1] = 0;
		m[0][2] = v.x;	m[1][2] = v.y;	m[2][2] = 1;
	}

	inline Vector2 Matrix33::GetTranslate()
	{
		return Vector2{ m[0][2], m[1][2] };
	}

	inline void Matrix33::Identity()
	{
		m[0][0] = 1; m[1][0] = 0; m[2][0] = 0;
		m[0][1] = 0; m[1][1] = 1; m[2][1] = 0;
		m[0][2] = 0; m[1][2] = 0; m[2][2] = 1;
	}

	inline Matrix33 Matrix33::operator * (const Matrix33& mx) const
	{
		Matrix33 result;

		result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1] + m[2][0] * mx.m[0][2];
		result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1] + m[2][0] * mx.m[1][2];
		result.m[2][0] = m[0][0] * mx.m[2][0] + m[1][0] * mx.m[2][1] + m[2][0] * mx.m[2][2];


		result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1] + m[2][1] * mx.m[0][2];
		result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1] + m[2][1] * mx.m[1][2];
		result.m[2][1] = m[0][1] * mx.m[2][0] + m[1][1] * mx.m[2][1] + m[2][1] * mx.m[2][2];

		result.m[0][2] = m[0][2] * mx.m[0][0] + m[1][2] * mx.m[0][1] + m[2][2] * mx.m[0][2];
		result.m[1][2] = m[0][2] * mx.m[1][0] + m[1][2] * mx.m[1][1] + m[2][2] * mx.m[1][2];
		result.m[2][2] = m[0][2] * mx.m[2][0] + m[1][2] * mx.m[2][1] + m[2][2] * mx.m[2][2];

		return result;
	}

	inline Vector2 Matrix33::operator * (const Vector2& v) const
	{
		Vector2 result;

		result[0] = v[0] * m[0][0] + v[1] * m[0][1] + 1 * m[0][2];
		result[1] = v[0] * m[1][0] + v[1] * m[1][1] + 1 * m[1][2];

		return result;
	}
}