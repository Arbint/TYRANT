#pragma once
#include "TyrantCore.h"
#include "SFML/Graphics.hpp"
namespace ty
{
	class TYRANT_API Level
	{
	public:
		Level(class Application* App);
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		const sf::Sprite& GetBackground() const { return m_Background; }
	private:
		class Application* m_app;
		sf::Sprite m_Background;
	};
}