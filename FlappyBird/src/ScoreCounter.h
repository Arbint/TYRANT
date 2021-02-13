#pragma once
#include <Entity.h>
#include <CollisionComp.h>
#include <MovementComp.h>
#include <VisualComp.h>
class ScoreCounter : public ty::Entity
{
public:
	ScoreCounter(class ty::Level* level);
	virtual sf::FloatRect GetBound() const override;
	void Collided(class Entity* other);
private:
	std::shared_ptr<ty::CollisionComp> m_CollisionComp;
	std::shared_ptr<ty::MovementComp> m_MovementComp;
	std::shared_ptr<ty::VisualComp> m_VisualComponents;
};