#include "MainLevel.h"
#include "MainLevelHud.h"
#include "iostream"
#include "Application.h"
MainLevelHud::MainLevelHud(ty::Level* level)
	: Hud(level)
{
	m_score.setFont(GetLevel()->GetApp()->LoadFont("FlappyFont.ttf"));
	m_score.setCharacterSize(80.f);
	m_score.setOrigin(m_score.getCharacterSize() / 2, 0);
	m_score.setString(std::to_string(0));
	m_score.setPosition(GetWindow()->getSize().x / 2, GetWindow()->getSize().y / 4);
	m_flash.setFillColor(sf::Color::White);
	m_flash.setSize(sf::Vector2f(GetWindow()->getSize().x, GetWindow()->getSize().y));
	
}

void MainLevelHud::TickHud(float DeltaTime)
{
	Hud::TickHud(DeltaTime);
}

void MainLevelHud::Draw()
{
	Hud::Draw();
 	GetWindow()->draw(m_score);
	//GetWindow()->draw(m_flash);
}
