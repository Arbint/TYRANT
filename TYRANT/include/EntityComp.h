#pragma once
#include <TyrantCore.h>
#include <SFML/Graphics.hpp>
namespace ty
{
	class TYRANT_API EntityComp
	{
	public:
		EntityComp(class Entity* Owner);
		class Entity* GetOwner() { return m_Owner; }
		virtual void TickComp(float DeltaTime);
		virtual void TransformationUpdated();
		virtual const sf::FloatRect GetBound() const { return sf::FloatRect(0.f, 0.f, 0.f, 0.f); }
	private:
		class Entity* m_Owner;
	};
}

