#pragma once
#include <TyrantCore.h>
#include <MovementComp.h>
namespace ty
{
	
	class TYRANT_API PhysicsComp : public MovementComp
	{
	public:
		PhysicsComp(class Entity* Owner);
		virtual void TickComp(float DeltaTime) override;
		void SetEnabled(bool enabled) { m_enabled = enabled; }
		void SetMass(float mass) { m_mass = mass; }
	private:
		sf::Clock m_Timer;
		bool m_enabled;
		float m_mass;
		float m_AirFraction;
		float m_Gravity;
	};
}

