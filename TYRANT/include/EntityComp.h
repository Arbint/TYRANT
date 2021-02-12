#pragma once
#include <TyrantCore.h>
namespace ty
{
	class TYRANT_API EntityComp
	{
	public:
		EntityComp(class Entity* Owner);
		class Entity* GetOwner() { return m_Owner; }
		virtual void TickComp(float DeltaTime);
		virtual void OnwerMoved(const sf::Vector2f& amt) {};
		virtual void OwnerRotated(float amt) {};
		virtual void OwnerTeleported(const sf::Vector2f& loc) {};
		virtual const sf::FloatRect GetBound() const { return sf::FloatRect(0.f, 0.f, 0.f, 0.f); }
	private:
		class Entity* m_Owner;
	};
}

