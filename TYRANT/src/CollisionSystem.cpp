#pragma once
#include "CollisionSystem.h"
namespace ty
{
	void CollisionSystem::CalculateCollision()
	{
		for (size_t i = 0; i < m_RegisteredComponents.size(); i++)
		{
			for (size_t j = 0; j < m_RegisteredComponents.size(); j++)
			{
				if (i != j)
				{
					sf::FloatRect IBound = m_RegisteredComponents[i]->GetOwnerBound();
					sf::FloatRect JBound = m_RegisteredComponents[j]->GetOwnerBound();
					if (JBound.intersects(IBound))
					{

					}
				}
			}
		}
	}
	void CollisionSystem::UnRegisterCollisionComp(std::shared_ptr<CollisionComp> CompToUnregister)
	{
		for (int i = 0; i < m_RegisteredComponents.size(); ++i)
		{
			if (m_RegisteredComponents[i] == CompToUnregister)
			{
				m_RegisteredComponents.erase(m_RegisteredComponents.begin() + i);
			}
		}
	}
}