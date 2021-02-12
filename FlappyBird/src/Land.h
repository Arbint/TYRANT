#pragma once
#include <Entity.h>

class Land : public ty::Entity {
public:
	Land(class ty::Level* level);
	void Tick(float DeltaTime);
private:
	sf::Sprite m_LandImageCpy;
	float m_LandMoveSpeed;
};