#include "ParticleSystem.h"
#include "Math/Random.h"
#include "Math/MathUtils.h"
#include "Graphics/Renderer.h"
#include "Graphics/Texture.h"

namespace luck
{
	void ParticleSystem::Startup()
	{
		particles.resize(1000000);
	}

	void ParticleSystem::Shutdown()
	{
		particles.clear();
	}

	void ParticleSystem::Update(float dt)
	{
		for (Particle& particle : particles)
		{
			if (particle.isActive)
			{
				particle.lifetime -= dt;
				particle.isActive = particle.lifetime > 0;
				particle.prevPosition = particle.position;
				particle.position += particle.velocity * dt;
				//particle.velocity.x *= (1 - dt / 4);
				//particle.velocity.y += (50 * dt);
				particle.angle = std::atan2(particle.velocity.x, particle.velocity.y);
			}
		}
	}

	void ParticleSystem::Draw(Renderer* renderer)
	{
		for (const Particle& particle : particles)
		{
			if (particle.isActive) {
				renderer->Draw(particle.texture, particle.position, particle.angle, 1);
			}
		}
	}

	void ParticleSystem::Create(const Vector2& position, size_t count, float lifetime, std::shared_ptr<Texture> texture, float speed)
	{
		for (size_t i = 0; i < count; i++)
		{
			auto particle = std::find_if(particles.begin(), particles.end(), Particle::isNotActive);
			if (particle != particles.end())
			{
				particle->isActive = true;
				particle->lifetime = lifetime;
				particle->position = position;
				particle->texture = texture;
				particle->prevPosition = position;
				float randX = RandomRange(-1, 1);
				float randY = RandomRange(-1, 1);
				particle->angle = std::atan2(randX, randY);
				particle->velocity = Vector2{ randX, randY } *(speed * Random());
			}
		}
	}

	void ParticleSystem::Create(const Vector2& position, size_t count, float lifetime, std::shared_ptr<Texture> texture, float speed, float angle, float angleRange)
	{
		for (size_t i = 0; i < count; i++)
		{
			auto particle = std::find_if(particles.begin(), particles.end(), Particle::isNotActive);
			if (particle != particles.end())
			{
				particle->isActive = true;
				particle->lifetime = lifetime;
				particle->position = position;
				particle->prevPosition = position;
				particle->texture = texture;
				float randX = RandomRange(-1, 1);
				float randY = RandomRange(-1, 1);
				particle->angle = std::atan2(randX, randY);
				particle->velocity = (luck::Vector2::Rotate(luck::Vector2::right, angle + luck::RandomRange(-angleRange, angleRange))) * (speed * Random());
			}
		}
	}
}