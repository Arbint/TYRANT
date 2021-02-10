#include "Bird.h"
#include <Application.h>
Bird::Bird(ty::Application* app)
	: Entity(app)
{
	SetVisual("bird-01.png");
	if (app && app->GetWindow())
	{
		sf::Vector2u windowSize = app->GetWindow()->getSize();
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
		std::cout << "tabed" << std::endl;
	}
}
