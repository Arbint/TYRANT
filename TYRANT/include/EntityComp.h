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
	private:
		class Entity* m_Owner;
	};
}

