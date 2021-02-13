#pragma once
#include <TyrantCore.h>
namespace ty
{
	class TYRANT_API Application
	{
	public:
		Application(int width, int height, const std::string& title);
		virtual void Pause();
		virtual void UnPause();
		virtual ~Application();
		virtual void Run();
		virtual void Tick(float DeltaTime);
		void TickLevel(float DeltaTime);
		virtual void LoadLevel(class Level* newLevel);
		const sf::Texture& LoadTexture(const std::string& name = "background.png");
		const sf::Font& LoadFont(const std::string& name = "");
		sf::RenderWindow* GetWindow() { return m_window; }
		float GetWindowWidth() const { return m_window->getSize().x; }
		float GetWindowHeight() const { return m_window->getSize().y; }
		sf::Vector2f GetWindowSize() const { return sf::Vector2f{GetWindowWidth(), GetWindowHeight()}; }
		virtual void HandleWindowEvents();
		virtual void HandleInput();
		class Level* GetCurrentLevel() { return m_CurrentLevel; }
		class CollisionSystem* GetCollisionSystem() { return m_CollisionSystem; }
	private:
		void UnLoadCurrentLevel();
	private:
		sf::RenderWindow* m_window;
		sf::Clock m_clock;
		class Level* m_CurrentLevel;
		std::map<std::string, sf::Texture> m_textureAssets;
		std::map<std::string, sf::Font> m_FontAssets;
		class CollisionSystem* m_CollisionSystem;
		bool m_Paused;
	};
}