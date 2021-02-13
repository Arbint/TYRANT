#pragma once
#include <EntityComp.h>
#include <functional>
namespace ty
{
	typedef std::function<void(void*, class Entity*)> CollisionResponseFuncPtr;
	class TYRANT_API CollisionComp : public EntityComp
	{
	public:
		CollisionComp(class Entity* owner);
		~CollisionComp();
		sf::FloatRect GetOwnerBound() const;
		
		void RegisterCollisionResponse(CollisionResponseFuncPtr ResponseFunc)
		{
			m_CollisionResponseFuc = ResponseFunc;
		}

		void InformCollisionEvent(class Entity* Other);
	private:
		CollisionResponseFuncPtr m_CollisionResponseFuc;
	};
}