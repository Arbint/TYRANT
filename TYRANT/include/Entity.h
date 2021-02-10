#pragma once
#include <TyrantCore.h>
#include <SFML/Graphics.hpp>

namespace ty
{
	class Entity;
	typedef  std::shared_ptr<Entity> EntitySharedRef;

	class TYRANT_API Entity
	{
	public:
		Entity(class Level* app);
		virtual ~Entity();
		virtual void BeginPlay();
		virtual void HandleInput();
		virtual void Tick(float DeltaTime);
		void SetVisual(const std::string& visualName);
		sf::Sprite& GetVisual() { return m_Visual; }
		class Level* GetLevel();
		class Application* GetApp() { return m_app; }
	private:
		sf::Sprite m_Visual;
		class Level* m_Level;
		class Application* m_app;
	};
}