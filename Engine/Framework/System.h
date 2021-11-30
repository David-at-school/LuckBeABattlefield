#pragma once

namespace luck
{
	class Renderer;

	class System
	{
	public:
		virtual void Startup() = 0;
		virtual void Shutdown() = 0;
		virtual void Update(float dt) = 0;
	};

	class GraphicsSystem : public System
	{
	public:
		virtual void Draw(Renderer* renderer) = 0;
	};
}