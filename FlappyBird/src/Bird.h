#pragma once
#include <Entity.h>
class Bird :
	public ty::Entity
{
public:
	Bird(class ty::Application* app);
	virtual void Tick(float DeltaTime) override;
	virtual void HandleInput() override;
private:
	sf::Clock m_Clock;
};

