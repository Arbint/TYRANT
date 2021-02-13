#include "EntityComp.h"
#include "Entity.h"
namespace ty
{
	EntityComp::EntityComp(Entity* Owner)
		: m_Owner(Owner)
	{

	}
	EntityComp::~EntityComp()
	{
		std::cout << "Entity Comp Destroied" << std::endl;
	}
	void EntityComp::TickComp(float DeltaTime)
	{

	}

	void EntityComp::TransformationUpdated()
	{

	}
}