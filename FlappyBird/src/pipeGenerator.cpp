#include "pipeGenerator.h"
#include "Pipe.h"
#include "Level.h"
#include <random>
#include <time.h>
#include <Application.h>
#include <iostream>
PipeGenerator::PipeGenerator(ty::Level* level)
	: Entity(level),
	m_SpawnIntervalSeconds(2),
	m_SpawnTimer(),
	m_LevelInterval(5.f),
	m_Gap(500.f),
	m_smallestGap(100.f),
	m_GapShrikPerLevel(50.f)
{
	float currentTime = std::time(nullptr);
	srand(currentTime);
}

void PipeGenerator::Tick(float DeltaTime)
{
	Entity::Tick(DeltaTime);
	if (m_SpawnTimer.getElapsedTime().asSeconds() >= m_SpawnIntervalSeconds)
	{
		SpawnPipes();
		m_SpawnTimer.restart();
	}
	if (GetLevel()->GetTimeSeconds() > m_LevelInterval)
	{
		m_LevelInterval += m_LevelInterval;
		m_Gap = m_Gap - m_GapShrikPerLevel;
		m_Gap = m_Gap > m_smallestGap ? m_Gap : m_smallestGap;
	}
}

void PipeGenerator::SpawnPipes()
{
	std::cout << "spawnning pipes" << std::endl;
	ty::EntitySharedRef TopPipe(new Pipe(GetLevel()));
	ty::EntitySharedRef BtmPipe(new Pipe(GetLevel()));
	GetLevel()->AddEntity(TopPipe);
	GetLevel()->AddEntity(BtmPipe);

	int PipeHeight = TopPipe->GetBound().height;
	float PipeStartXLocation = GetApp()->GetWindow()->getSize().x;
	float TopPipeYLocation = rand()%PipeHeight - PipeHeight;
	float BtmPipeYLocation = TopPipeYLocation + m_Gap;
	TopPipe->SetLocation(sf::Vector2f(PipeStartXLocation, TopPipeYLocation));
	BtmPipe->SetLocation(sf::Vector2f(PipeStartXLocation, BtmPipeYLocation));
}
