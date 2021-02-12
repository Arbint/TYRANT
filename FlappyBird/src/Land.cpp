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
	m_landOne->SetZOrder(1);
	m_landTwo->SetZOrder(1);
	
	m_MoveComp->SetVelocity(sf::Vector2f(-100.f, 0.f));
	SetLocation(sf::Vector2f(0.f, GetApp()->GetWindow()->getSize().y - m_landOne->GetBound().height));
}

void Land::Move(const sf::Vector2f& moveAmt)
{
	Entity::Move(moveAmt);
	m_landTwo->GetVisual().setPosition(m_landOne->GetVisual().getPosition().x + m_landTwo->GetBound().width, GetPosition().y);
	if (m_landTwo->GetVisual().getPosition().x <= 0)
	{
		SetLocation(sf::Vector2f(0.f, GetApp()->GetWindow()->getSize().y - m_landTwo->GetBound().height));
	}
}
