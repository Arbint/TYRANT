#pragma once
#include <TyrantCore.h>
namespace ty
{
	class TYRANT_API Application
	{
	public:
		Application(int width, int height, const std::string& title);
		virtual ~Application();
		virtual void Run();
		virtual void Tick(float DeltaTime);
		void TickLevel(float DeltaTime);
		virtual void LoadLevel(class Level* newLevel);
		const sf::Texture& LoadTexture(const std::string& name = "sky.png");
	private:
		void UnLoadCurrentLevel();
	private:
		sf::RenderWindow* m_window;
		sf::Clock m_clock;
		class Level* m_CurrentLevel;
		std::map<std::string, sf::Texture> m_textureAssets;
	};
}