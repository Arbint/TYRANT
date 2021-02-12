#include "Pipe.h"
#include "Level.h"
#include "MovementComp.h"
#include "Application.h"
Pipe::Pipe(ty::Level* level)
	: Entity(level),
	m_Speed(-80.f)
{
	m_movementComp = ConstructComponent<ty::MovementComp>();
	m_visualComp = ConstructComponent<ty::VisualComp>();
	m_visualComp->SetTexture("Pipe.png");	
	m_movementComp->SetVelocity(sf::Vector2f(m_Speed, 0.f));
	SetLocation(sf::Vector2f(GetApp()->GetWindow()->getSize().x, 0));
}
