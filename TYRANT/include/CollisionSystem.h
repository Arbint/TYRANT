#pragma once
#include "TyrantCore.h"
#include "CollisionComp.h"
namespace ty
{
	class TYRANT_API CollisionSystem
	{
	public:
		void RegisterCollisionComp(class CollisionComp* newComp) { m_RegisteredComponents.push_back(newComp); }
		void CalculateCollision();
		void UnRegisterCollisionComp(class CollisionComp* comp);
	private:
		std::vector<class CollisionComp*> m_RegisteredComponents;
	};
}