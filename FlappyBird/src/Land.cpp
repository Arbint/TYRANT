#include "Land.h"
#include "Level.h"
#include "Application.h"
Land::Land(ty::Level* level)
	:	Entity(level),
	m_LandMoveSpeed(20.f)
{
	GetVisual().setTexture(GetApp()->LoadTexture("land.png"));
	m_LandImageCpy.setTexture(GetApp()->LoadTexture("land.png"));
	GetVisual().setPosition(0.f, GetApp()->GetWindow()->getSize().y - GetVisual().getGlobalBounds().height);
}

void Land::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	GetVisual().move(-m_LandMoveSpeed * DeltaTime, 0);
	m_LandImageCpy.setPosition(GetVisual().getPosition().x + m_LandImageCpy.getGlobalBounds().width, GetVisual().getPosition().y);
	if (m_LandImageCpy.getPosition().x <= 0)
	{
		GetVisual().setPosition(0.f, GetApp()->GetWindow()->getSize().y - GetVisual().getGlobalBounds().height);
	}
}
