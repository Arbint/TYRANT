#pragma once
#include <Entity.h>
#include <MovementComp.h>
#include <VisualComp.h>
#include <CollisionComp.h>
class Pipe : public ty::Entity
{
public:
	Pipe(class ty::Level* Level);
	virtual void Tick(float DeltaTime) override;
private:
	std::shared_ptr<ty::MovementComp>m_movementComp;
	std::shared_ptr<ty::VisualComp> m_visualComp;
	std::shared_ptr<ty::CollisionComp> m_collisionComp;
	float m_Speed;
};

