#pragma once
#include "Object.h"
#include "Core/Serializable.h"
#include <vector>

namespace luck
{
	class Tilemap : public Object, public ISerializable
	{
	public:
		void Create() override;

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		class Scene* scene = nullptr;

		int numTilesX{ 0 };
		int numTilesY{ 0 };
		Vector2 start;
		Vector2 size;
		std::vector<std::string> tileNames;
		std::vector<int> tiles;
	};
}