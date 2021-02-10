#include "MovementComp.h"
#include "Entity.h"
namespace ty
{
	MovementComp::MovementComp(Entity* Owner)
		: EntityComp(Owner)
	{

	}

	void MovementComp::TickComp(float DeltaTime)
	{
		if (GetOwner())
		{
			GetOwner()->Move(m_vel * DeltaTime);
		}
	}

	void MovementComp::SetVelocity(const sf::Vector2f& newVel)
	{
		m_vel = newVel;
	}

	void MovementComp::AddVelocity(const sf::Vector2f& vel)
	{
		m_vel += vel;
	}

}

