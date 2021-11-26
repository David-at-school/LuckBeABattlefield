#pragma once
#include "Math/Vector2.h"
#include "Framework/System.h"
#include <vector>

namespace luck
{
	class Texture;

	struct Particle
	{
		Vector2 position;
		Vector2 prevPosition;
		Vector2 velocity;
		std::shared_ptr<Texture> texture;
		float lifetime;
		float angle;
		bool isActive{ false };

		static bool isNotActive(Particle particle) { return !particle.isActive; }
	};

	class ParticleSystem : public GraphicsSystem
	{
	public:
		void Startup() override;
		void Shutdown() override;

		void Update(float dt) override;
		void Draw(class Renderer* renderer) override;

		void Create(const Vector2& position, size_t count, float lifetime, std::shared_ptr<Texture> texture, float speed);
		void Create(const Vector2& position, size_t count, float lifetime, std::shared_ptr<Texture> texture, float speed, float angle, float angleRange);

	public:
		std::vector<Particle> particles;
	};
}