#include "Land.h"
#include "Level.h"
#include "Application.h"

Land::Land(ty::Level* level)
	:	Entity(level)
{
	m_landOne = ConstructComponent<ty::VisualComp>();
	m_landTwo = ConstructComponent<ty::VisualComp>();
	m_MoveComp = ConstructComponent<ty::MovementComp>();

	m_landOne->SetTexture("land.png");
	m_landTwo->SetTexture("land.png");
	m_landOne->SetZOrder(2);
	m_landTwo->SetZOrder(2);
	m_MoveComp->SetVelocity(sf::Vector2f(-80.f, 0.f));
	SetPosition(sf::Vector2f(0.f, GetApp()->GetWindow()->getSize().y - m_landOne->GetBound().height));
	m_landTwo->SetLocalLocation(sf::Vector2f(m_landTwo->GetBound().width, 0.f));
}

void Land::Move(const sf::Vector2f& moveAmt)
{
	Entity::Move(moveAmt);
	if (m_landTwo->GetVisual().getPosition().x <= 0)
	{
		SetPosition(sf::Vector2f(0.f, GetApp()->GetWindow()->getSize().y - m_landTwo->GetBound().height));
	}
}
