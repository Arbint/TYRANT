#pragma once
#include <TyrantCore.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
namespace ty
{
	class TYRANT_API Application
	{
	public:
		Application(int width, int height, const std::string& title);
		virtual ~Application();
		virtual void Run();
		virtual void Tick(float DeltaTime);
		virtual void LoadLevel(class Level* newLevel);
	private:
		void UnLoadCurrentLevel();
	private:
		sf::RenderWindow* m_window;
		sf::Clock m_clock;
		class Level* m_CurrentLevel;
	};
}