#pragma once
#include "TyrantCore.h"
#include "SFML/Graphics.hpp"
#include <Entity.h>
#include <PhysicsComp.h>
namespace ty
{
	class TYRANT_API Level
	{
	public:
		Level(class Application* App);
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
		virtual void Draw();
		virtual void DrawBackground();
		virtual void DrawEntities();
		virtual void DrawForground();
		virtual void HandleInput();
		sf::Sprite& GetBackground() { return m_Background; }
		std::vector<EntitySharedRef>& GetEntities() { return m_Entities; }
		void AddEntity(EntitySharedRef newEntity);
		class Application* GetApp() { return m_app; }
		float GetTimeSeconds() const { return m_GlobalTimer.getElapsedTime().asSeconds(); }
	private:
		class Application* m_app;
		sf::Sprite m_Background;
		std::vector<EntitySharedRef> m_Entities;
		sf::Clock m_GlobalTimer;
	};
}