#pragma once
#include <TyrantCore.h>
#include <EntityComp.h>
namespace ty
{
	
	class TYRANT_API PhysicsComp : public EntityComp
	{
	public:
		PhysicsComp(class Entity* Owner);
		virtual void TickComp(float DeltaTime) override;
		void SetEnabled(bool enabled) { m_enabled = enabled; }
		void SetMass(float mass) { m_mass = mass; }
		void AddImpulse(const sf::Vector2f& impulse);
		void SetVel(const sf::Vector2f& vel);
	private:
		sf::Clock m_Timer;
		bool m_enabled;
		float m_mass;
		sf::Vector2f m_velocity;
	};
}

