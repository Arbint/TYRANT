#include "..\include\PhysicsComp.h"
#include "PhysicsComp.h"
#include "Level.h"

namespace ty{ 
	PhysicsComp::PhysicsComp(Entity* Owner)
		: MovementComp(Owner),
		m_enabled(true),
		m_mass(1.f),
		m_AirFraction(0.2),
		m_Gravity(980.f)
	{

	}

	void PhysicsComp::TickComp(float DeltaTime)
	{
		MovementComp::TickComp(DeltaTime);
		if (m_enabled && GetOwner())
		{
			sf::Vector2f GravityAcc(0.f, DeltaTime * m_Gravity);
			sf::Vector2f AirFractionAcc = - GetVelocity() * m_AirFraction * DeltaTime;
			AddVelocity(GravityAcc + AirFractionAcc);
		}
	}
}