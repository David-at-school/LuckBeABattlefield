#pragma once
#include "Component.h"

namespace luck
{
	class Renderer;

	class GraphicsComponent : public Component
	{
	public:
		virtual void Draw(Renderer* renderer) = 0;
	};
}