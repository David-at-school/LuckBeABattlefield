#pragma once
#include "Object/Object.h"
#include "Core/Serializable.h"

namespace luck
{
	class Actor;

	class Component : public Object, public ISerializable
	{
	public:
		virtual void Update() = 0;

		virtual bool Write(const rapidjson::Value& value) const = 0;
		virtual bool Read(const rapidjson::Value& value) = 0;

	public:
		Actor* owner{ nullptr };
	};
}