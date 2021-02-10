#include "MainLevel.h"
#include <Application.h>
#include <Entity.h>
#include "Bird.h"
MainLevel::MainLevel(ty::Application* app)
	: Level(app),
	m_BackgroundMoveSpeed(40.f)
{
	AddEntity(ty::EntitySharedRef(new Bird(app)));
	m_background_rep.setTexture(*GetBackground().getTexture());
}

void MainLevel::Tick(float DeltaTime)
{
	Level::Tick(DeltaTime);
	GetBackground().move(-DeltaTime * m_BackgroundMoveSpeed,0);
	m_background_rep.setPosition(GetBackground().getPosition().x + m_background_rep.getGlobalBounds().width, 0);
	if (GetBackground().getPosition().x <= - GetBackground().getGlobalBounds().width)
	{
		GetBackground().setPosition(0, 0);
	}
}

void MainLevel::DrawBackground()
{
	Level::DrawBackground();
	GetApp()->GetWindow()->draw(m_background_rep);
}