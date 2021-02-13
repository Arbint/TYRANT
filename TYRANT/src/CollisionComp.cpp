#include "CollisionComp.h"
#include "Entity.h"
#include "Application.h"
#include "CollisionSystem.h"
namespace ty
{ 
	CollisionComp::CollisionComp(Entity* owner)
		: EntityComp(owner)
	{
		GetOwner()->GetApp()->GetCollisionSystem()->RegisterCollisionComp(this);
	}
	CollisionComp::~CollisionComp()
	{
		GetOwner()->GetApp()->GetCollisionSystem()->UnRegisterCollisionComp(this);
	}
	sf::FloatRect CollisionComp::GetOwnerBound() const
	{
		return GetOwner()->GetBound();
	}

	void CollisionComp::InformCollisionEvent(Entity* Other)
	{
		if (m_CollisionResponseFuc)
		{
			m_CollisionResponseFuc(nullptr, Other);
		}
	}
}