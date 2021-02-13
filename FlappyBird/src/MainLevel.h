#pragma once
#include <Level.h>
class MainLevel : public ty::Level
{
public:
	MainLevel(class ty::Application* app);
	virtual void Tick(float DeltaTime) override;
	virtual void DrawBackground() override;
private:
	float m_BackgroundMoveSpeed;
	sf::Sprite m_background_rep;

//debug:
	class ty::Entity* pipeTest;
};

