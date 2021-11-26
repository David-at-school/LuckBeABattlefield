#pragma once
#include "Resource/Resource.h"
#include "Math/Vector2.h"
#include <SDL.h>

namespace luck
{
	class Renderer;

	class Texture : public Resource
	{
	public:
		Texture() {}
		Texture(Renderer* renderer);

		bool Load(const std::string& name, void* data) override;

		bool Create(SDL_Surface* surface);

		Vector2 GetSize();

		friend class Renderer;
	private:
		SDL_Texture* texture{ nullptr };
		SDL_Renderer* renderer{ nullptr };
	};
}