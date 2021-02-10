#pragma once
#include <Entity.h>
#include <PhysicsComp.h>
class Bird :
	public ty::Entity
{
public:
	Bird(class ty::Level* app);
	virtual void Tick(float DeltaTime) override;
	virtual void HandleInput() override;
private:
	sf::Clock m_Clock;
	ty::PhysicsComp m_PhysicsComp;
};

