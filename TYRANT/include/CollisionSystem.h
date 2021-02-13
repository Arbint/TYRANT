#pragma once
#include "TyrantCore.h"
#include "CollisionComp.h"
namespace ty
{
	class TYRANT_API CollisionSystem
	{
	public:
		void RegisterCollisionComp(std::shared_ptr<CollisionComp> newComp) { m_RegisteredComponents.push_back(newComp); }
		void CalculateCollision();
		void UnRegisterCollisionComp(std::shared_ptr<CollisionComp> CompToUnregister);
	private:
		std::vector<std::shared_ptr<CollisionComp>> m_RegisteredComponents;
	};
}