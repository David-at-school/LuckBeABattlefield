#pragma once
#include "Matrix33.h"
#include "Core/Serializable.h"

namespace luck
{
	struct Transform : public ISerializable
	{
		Vector2 position;
		float rotation = 0;
		Vector2 scale = 1;
		
		Vector2 localPosition;
		float localRotation = 0;
		Vector2 localScale = 1;

		Matrix33 matrix;

		Transform() {}
		Transform(const Vector2& position, float rotation = 0.0f, float scale = 1.0f) : position{ position }, rotation{ rotation }, scale{ scale } {}

		void Update();
		void Update(const Matrix33& mx);

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}