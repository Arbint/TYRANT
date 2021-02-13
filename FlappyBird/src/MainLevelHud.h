#pragma once
#include "Hud.h"

class MainLevelHud : public ty::Hud
{
public:
	MainLevelHud(class ty::Level* level);
	virtual void TickHud(float DeltaTime) override;
	virtual void Draw()  override;

private:
	sf::Text m_score;
	sf::RectangleShape m_flash;
};