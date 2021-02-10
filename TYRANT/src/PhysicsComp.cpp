#include "..\include\PhysicsComp.h"
#include "PhysicsComp.h"
#include "Level.h"
#define GRAVITY 980.f;
namespace ty{ 
	PhysicsComp::PhysicsComp(Entity* Owner)
		: EntityComp(Owner),
		m_enabled(true),
		m_mass(1.f),
		m_velocity(0,0)
	{

	}

	void PhysicsComp::TickComp(float DeltaTime)
	{
		if (m_enabled && GetOwner())
		{
			m_velocity.y += DeltaTime * GRAVITY;
			std::cout << "vel is: " << m_velocity.y << std::endl;
			sf::Vector2f movment = m_velocity * DeltaTime;
			sf::Sprite& OwnerVisual = GetOwner()->GetVisual();
			OwnerVisual.move(movment);
			std::cout << "owner loc y :" << OwnerVisual.getPosition().y << std::endl;
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