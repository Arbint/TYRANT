#pragma once
#include <Entity.h>
#include <VisualComp.h>
#include <MovementComp.h>
class Land : public ty::Entity {
public:
	Land(class ty::Level* level);
	virtual void Move(const sf::Vector2f& moveAmt) override;
private:
	std::shared_ptr<ty::VisualComp> m_landOne;
	std::shared_ptr<ty::VisualComp> m_landTwo;
	std::shared_ptr<ty::MovementComp> m_MoveComp;
};