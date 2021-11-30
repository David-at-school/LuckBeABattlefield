#pragma once

#define REGISTER_CLASS(CLASS) luck::ObjectFactory::Instance().Register<CLASS>(#CLASS);

//audio
#include "Audio/AudioSystem.h"

//core
#include "Core/FileSystem.h"
#include "Core/Json.h"
#include "Core/Serializable.h"
#include "Core/Timer.h"
#include "Core/Utilities.h"

// framework
#include "Framework/EventSystem.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"

// input
#include "Input/InputSystem.h"

//math
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/MathUtils.h"
#include "Math/Random.h"
#include "Math/Transform.h"

// graphics
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"
#include "Graphics/Font.h"
#include "Graphics/ParticleSystem.h"

//resource
#include "Resource/ResourceSystem.h"

//object
#include "Object/Actor.h"
#include "Object/Scene.h"
#include "Object/Tilemap.h"

// component
#include "Component/SpriteComponent.h"
#include "Component/SpriteAnimationComponent.h"
#include "Component/AudioComponent.h"
#include "Component/TextComponent.h"

#define NOMINMAX
#include <vector>
#include <memory>
#include <algorithm>
#include <SDL_image.h>

namespace luck
{
	using ObjectFactory = Singleton<Factory<std::string, Object>>;

	class Engine
	{
	public:
		void Startup();
		void Shutdown();

		void Update();
		void Draw(Renderer* renderer);

		template<typename T>
		T* Get();

	public:
		FrameTimer time;

	private:
		std::vector<std::unique_ptr<System>> systems;

	};

	template<typename T>
	inline T* Engine::Get()
	{
		for (auto& system : systems)
		{
			if (dynamic_cast<T*>(system.get())) return dynamic_cast<T*>(system.get());
		}

		return nullptr;
	}
}