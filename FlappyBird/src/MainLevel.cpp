#include "MainLevel.h"
#include <Application.h>
#include <Entity.h>
#include "Bird.h"
#include "pipeGenerator.h"
#include "Land.h"
#include "Pipe.h"
MainLevel::MainLevel(ty::Application* app)
	: Level(app),
	m_BackgroundMoveSpeed(40.f)
{
	AddEntity(ty::EntitySharedRef(new Bird(this)));
	AddEntity(ty::EntitySharedRef(new PipeGenerator(this)));
	AddEntity(ty::EntitySharedRef(new Land(this)));
	m_background_rep.setTexture(*GetBackground().getTexture());

	//debug
	ty::EntitySharedRef pipeTop(new Pipe(this));
	pipeTop->SetPosition(sf::Vector2f(768/2, 1024/2));
	pipeTop->Move(sf::Vector2f(69/2, 0.f));
	//pipeTop->SetRelativeOrigin(sf::Vector2f(69/4,0.f));
	
	AddEntity(pipeTop);
	pipeTest = pipeTop.get();

	ty::EntitySharedRef pipeBtm(new Pipe(this));
	pipeBtm->Move(sf::Vector2f(0.f, app->GetWindow()->getSize().y - 368));
	//AddEntity(pipeBtm);

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

	//debug
	//pipeTest->SetRotation(pipeTest->getRotation() + DeltaTime * 10.f);
}

void MainLevel::DrawBackground()
{
	Level::DrawBackground();
	GetApp()->GetWindow()->draw(m_background_rep);

	//debug:
	sf::Sprite line;
	line.setTexture(GetApp()->LoadTexture("verticalLine.png"));
	line.setPosition(768/2, 0.f);
	sf::Sprite line2;
	line2.setTexture(GetApp()->LoadTexture("horiontalLine.png"));
	line2.setPosition(0.f, 1024 / 2);
	GetApp()->GetWindow()->draw(line);
	GetApp()->GetWindow()->draw(line2);
}
