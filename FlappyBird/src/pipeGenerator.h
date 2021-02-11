#pragma once
#include <Entity.h>

class PipeGenerator : public ty::Entity
{
public:
	PipeGenerator(class ty::Level* level);
	virtual void Tick(float DeltaTime) override;
private:
	sf::Clock m_SpawnTimer;
	int m_Gap;
	int m_GapShrikPerLevel;
	int m_smallestGap;
	float m_LevelInterval;
	float m_SpawnIntervalSeconds;
	void SpawnPipes();
};