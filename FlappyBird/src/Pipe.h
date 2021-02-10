#pragma once
#include <Entity.h>
#include <MovementComp.h>
class Pipe : public ty::Entity
{
public:
	Pipe(class ty::Level* Level);
private:
	std::shared_ptr<ty::MovementComp>m_movementComp;
	float m_Speed;
};

