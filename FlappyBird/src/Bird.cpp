#include "Bird.h"
#include <Application.h>
Bird::Bird(ty::Level* level)
	: Entity(level),
	m_PhysicsComp(this)
{
	SetVisual("bird-01.png");
	if (GetApp() && GetApp()->GetWindow())
	{
		sf::Vector2u windowSize = GetApp()->GetWindow()->getSize();
		GetVisual().setOrigin(GetVisual().getGlobalBounds().width / 2, GetVisual().getGlobalBounds().height / 2);
		GetVisual().setPosition(windowSize.x/4, windowSize.y/2);
	}
}

void Bird::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
}

void Bird::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_PhysicsComp.SetVel(sf::Vector2f(0.f, -400.f));
	}
}
