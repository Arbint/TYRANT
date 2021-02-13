#include "Bird.h"
#include <Application.h>
#include <VisualComp.h>
#include <PhysicsComp.h>
#include <type_traits>
#include <typeinfo>
#include <typeindex>
#include "Pipe.h"
#include <TypeUtilities.h>
Bird::Bird(ty::Level* level)
	: Entity(level)
{
	m_BirdVirsual = ConstructComponent<ty::VisualComp>();
	if (m_BirdVirsual)
	{
		m_BirdVirsual->SetTexture("bird.png");
		m_BirdVirsual->SetOrigin(
			sf::Vector2f(m_BirdVirsual->GetVisual().getGlobalBounds().width / 2,
			m_BirdVirsual->GetVisual().getGlobalBounds().height / 2)
		);
		m_BirdVirsual->SetZOrder(1);

		m_CollisionComp = ConstructComponent<ty::CollisionComp>();
		if (m_CollisionComp)
		{
			m_CollisionComp->RegisterCollisionResponse(std::bind(&Bird::Collided, this, std::placeholders::_2));
		}
	}

	if (GetApp() && GetApp()->GetWindow())
	{
		sf::Vector2u windowSize = GetApp()->GetWindow()->getSize();
		SetPosition(sf::Vector2f(768/2, 1024/2));
		SetPosition(sf::Vector2f(windowSize.x / 4, windowSize.y / 2));
	}
	m_PhysicsComp = ConstructComponent<ty::PhysicsComp>();
}

void Bird::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	SetRelativeOrigin(GetRelativeOrigin() + sf::Vector2f(10.f * DeltaTime, 0));
}

void Bird::HandleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_PhysicsComp->SetVelocity(sf::Vector2f(0.f, -400.f));
	}
}

void Bird::Collided(ty::Entity* other)
{
	if (ty::IsOfType<Pipe>(other))
	{
		GetApp()->Pause();
	}
}
