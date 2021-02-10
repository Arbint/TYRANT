#pragma once
#include <TyrantCore.h>

namespace ty
{
	
	class TYRANT_API PhysicsComp
	{
	public:
		PhysicsComp(class Entity* Owner);
		void TickPhysics(float DeltaTime);
		void SetEnabled(bool enabled) { m_enabled = enabled; }
		void SetMass(float mass) { m_mass = mass; }
		void AddImpulse(const sf::Vector2f& impulse);
		void SetVel(const sf::Vector2f& vel);
	private:
		sf::Clock m_Timer;
		class Entity* m_Owner;
		bool m_enabled;
		float m_mass;
		sf::Vector2f m_velocity;
	};
}

