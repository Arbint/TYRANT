#pragma once
#include "TyrantCore.h"
#include "SFML/Graphics.hpp"
namespace ty
{
	class TYRANT_API Hud {
	public:
		Hud(class Level* level);
		virtual void TickHud(float DeltaTime);
		virtual void Draw();
		class Level* GetLevel() { return m_level; }
		sf::RenderWindow* GetWindow();
	private:
		class Level* m_level;
	};
}