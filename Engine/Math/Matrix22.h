#pragma once
#include "Vector2.h"

namespace luck
{
	struct Matrix22
	{
		float m[2][2]; // [column][row]

		Matrix22();
		Matrix22( const Vector2& column1, const Vector2& column2);

		void Scale(float s);
		void Scale(float sx, float sy);
		void Scale(const Vector2& s);

		void Rotate(float angle);

		void Identity();

		Matrix22 operator * (const Matrix22& mx) const;
		Vector2 operator * (const Vector2& v) const;
	};

	inline Matrix22::Matrix22()
	{
		m[0][0] = 0; m[1][0] = 0;
		m[0][1] = 0; m[1][1] = 0;
	}

	inline Matrix22::Matrix22(const Vector2& column1, const Vector2& column2) 
	{
		m[0][0] = column1[0]; m[1][0] = column2[0];
		m[0][1] = column1[1]; m[1][1] = column2[1];
	}

	inline void Matrix22::Scale(float s)
	{
		m[0][0] = s; m[1][0] = 0;
		m[0][1] = 0; m[1][1] = s;
	}

	inline void Matrix22::Scale(float sx, float sy)
	{
		m[0][0] = sx; m[1][0] = 0;
		m[0][1] = 0; m[1][1] = sy;
	}

	inline void Matrix22::Scale(const Vector2& s)
	{
		m[0][0] = s.x; m[1][0] = 0;
		m[0][1] = 0; m[1][1] = s.y;
	}

	inline void Matrix22::Rotate(float angle)
	{
		m[0][0] = std::cos(angle); m[1][0] = std::sin(angle);
		m[0][1] = -std::sin(angle); m[1][1] = std::cos(angle);
	}

	inline void Matrix22::Identity()
	{
		m[0][0] = 1; m[1][0] = 0;
		m[0][1] = 0; m[1][1] = 1;
	}

	inline Matrix22 Matrix22::operator * (const Matrix22& mx) const
	{
		Matrix22 result;

		result.m[0][0] = m[0][0] * mx.m[0][0] + m[1][0] * mx.m[0][1];
		result.m[1][0] = m[0][0] * mx.m[1][0] + m[1][0] * mx.m[1][1];
		result.m[0][1] = m[0][1] * mx.m[0][0] + m[1][1] * mx.m[0][1];
		result.m[1][1] = m[0][1] * mx.m[1][0] + m[1][1] * mx.m[1][1];

		return result;
	}

	inline Vector2 Matrix22::operator * (const Vector2& v) const
	{
		Vector2 result;

		result[0] = v[0] * m[0][0] + v[1] * m[0][1];
		result[1] = v[0] * m[1][0] + v[1] * m[1][1];
			
		return result;
	}
}
