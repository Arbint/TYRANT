#pragma once
#include <Entity.h>
#include <PhysicsComp.h>
#include <VisualComp.h>

class Bird :
	public ty::Entity
{
public:
	Bird(class ty::Level* app);
	virtual void Tick(float DeltaTime) override;
	virtual void HandleInput() override;
private:
	sf::Clock m_Clock;
	std::shared_ptr<class ty::PhysicsComp> m_PhysicsComp;
	std::shared_ptr<class ty::VisualComp> m_BirdVirsual;
};

