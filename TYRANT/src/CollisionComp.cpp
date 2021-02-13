#include "CollisionComp.h"
#include "Entity.h"
namespace ty
{ 
	CollisionComp::CollisionComp(Entity* owner)
		: EntityComp(owner),
		m_CollisionResponseFuc()
	{

	}
	sf::FloatRect CollisionComp::GetOwnerBound() const
	{
		return GetOwner()->GetBound();
	}
	void CollisionComp::InformCollisionEvent(Entity* Other)
	{
		m_CollisionResponseFuc(nullptr, Other);
	}
}