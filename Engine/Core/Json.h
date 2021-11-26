#pragma once
#include "document.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include <string>
#include <vector>

#define JSON_READ(value, data) luck::json::Get(value, #data, data);

namespace luck
{
	namespace json
	{
		bool Load(const std::string& filename, rapidjson::Document& document);
		bool Get(const rapidjson::Value& value, const std::string& name, int& data);
		bool Get(const rapidjson::Value& value, const std::string& name, float& data);
		bool Get(const rapidjson::Value& value, const std::string& name, bool& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::string& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Vector2& data);
		bool Get(const rapidjson::Value& value, const std::string& name, Color& data);
		bool Get(const rapidjson::Value& value, const std::string& name, SDL_Rect& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<std::string>& data);
		bool Get(const rapidjson::Value& value, const std::string& name, std::vector<int>& data);
	}
}