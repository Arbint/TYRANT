#include "..\include\PhysicsComp.h"
#include "PhysicsComp.h"
#include "Level.h"
#define GRAVITY 980.f;
namespace ty{ 
	PhysicsComp::PhysicsComp(Entity* Owner)
		: EntityComp(Owner),
		m_enabled(true),
		m_mass(1.f),
		m_velocity(0,0),
		m_AirFraction(0.2)
	{

	}

	void PhysicsComp::TickComp(float DeltaTime)
	{
		if (m_enabled && GetOwner())
		{
			m_velocity.y += DeltaTime * GRAVITY;
			m_velocity -= m_velocity * m_AirFraction * DeltaTime;
			sf::Vector2f movment = m_velocity * DeltaTime;
			GetOwner()->Move(movment);
		}
	}
	void PhysicsComp::AddImpulse(const sf::Vector2f& impulse)
	{
		m_velocity += impulse;
	}
	void PhysicsComp::SetVel(const sf::Vector2f& vel)
	{
		m_velocity = vel;
	}
}