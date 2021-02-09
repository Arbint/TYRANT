#pragma once
#include "TyrantCore.h"
#include "SFML/Graphics.hpp"
namespace ty
{
	class TYRANT_API Level
	{
	public:
		Level(class Application* app);
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
	private:
		sf::Sprite m_Background;
		class Application* m_app;
	};
}