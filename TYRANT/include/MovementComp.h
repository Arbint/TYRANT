#pragma once
#include <EntityComp.h>
#include <SFML/System.hpp>
namespace ty
{
	class TYRANT_API  MovementComp : public EntityComp 
	{
	public:
		MovementComp(class Entity* Owner);
		virtual void TickComp(float DeltaTime) override;
		void SetVelocity(const sf::Vector2f& newVel);
		const sf::Vector2f& GetVelocity() const { return m_vel; }
		void AddVelocity(const sf::Vector2f& vel);
	private:
		sf::Vector2f m_vel;
	};
}

