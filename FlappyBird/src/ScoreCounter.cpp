#include "ScoreCounter.h"
#include <functional>
#include <TypeUtilities.h>
#include "Bird.h"
#include <Application.h>
ScoreCounter::ScoreCounter(class ty::Level* level)
	: Entity(level)
{
	m_MovementComp = ConstructComponent<ty::MovementComp>();
	m_MovementComp->SetVelocity(sf::Vector2f(-80.f, 0.f));
	m_CollisionComp = ConstructComponent<ty::CollisionComp>();
	m_CollisionComp->RegisterCollisionResponse(std::bind(&ScoreCounter::Collided, this, std::placeholders::_2));
	
	m_VisualComponents = ConstructComponent<ty::VisualComp>();
	if (m_VisualComponents)
	{
		m_VisualComponents->SetTexture("verticalLine.png");
	}
}

sf::FloatRect ScoreCounter::GetBound() const
{
	return sf::FloatRect(GetPosition(), sf::Vector2f(20.f, GetApp()->GetWindowHeight()));
}

void ScoreCounter::Collided(class Entity* other)
{
	if (ty::IsOfType<Bird>(other))
	{
		std::cout << "score up" << std::endl;
		Destory();
	}
}
