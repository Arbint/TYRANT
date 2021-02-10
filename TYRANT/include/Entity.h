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
		Entity(class Application* app);
		virtual ~Entity();
		virtual void BeginPlay();
		virtual void HandleInput();

		virtual void Tick(float DeltaTime);
		void SetVisual(const std::string& visualName);
		sf::Sprite& GetVisual() { return m_Visual; }
	private:
		sf::Sprite m_Visual;
		class Application* m_app;
	};
}