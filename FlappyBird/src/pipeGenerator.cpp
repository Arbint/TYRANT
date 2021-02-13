#include "pipeGenerator.h"
#include "Pipe.h"
#include "Level.h"
#include <random>
#include <time.h>
#include <Application.h>
#include <iostream>
#include "ScoreCounter.h"
PipeGenerator::PipeGenerator(ty::Level* level)
	: Entity(level),
	m_SpawnIntervalSeconds(1),
	m_SpawnTimer(),
	m_LevelInterval(5.f),
	m_Gap(800.f),
	m_smallestGap(300.f),
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
		m_SpawnIntervalSeconds = 3 + rand() % 5;
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
	ty::EntitySharedRef TopPipe(new Pipe(GetLevel()));
	ty::EntitySharedRef BtmPipe(new Pipe(GetLevel()));
	GetLevel()->AddEntity(TopPipe);
	GetLevel()->AddEntity(BtmPipe);
	int PipeHeight = TopPipe->GetBound().height;
	int PipeWidth = TopPipe->GetBound().width;
	TopPipe->SetRelativeOrigin(sf::Vector2f(PipeWidth/2, PipeHeight/2));
	BtmPipe->SetRelativeOrigin(TopPipe->GetRelativeOrigin());
	TopPipe->SetRotation(180);
	float PipeStartXLocation = GetApp()->GetWindow()->getSize().x + PipeWidth/2;
	float TopPipeYLocation = rand()%(PipeHeight/2);
	float BtmPipeYLocation = TopPipeYLocation + m_Gap;
	TopPipe->SetPosition(sf::Vector2f(PipeStartXLocation, TopPipeYLocation));
	BtmPipe->SetPosition(sf::Vector2f(PipeStartXLocation, BtmPipeYLocation));
	
	ty::EntitySharedRef scoreCounter(new ScoreCounter(GetLevel()));
	scoreCounter->SetPosition(sf::Vector2f(PipeStartXLocation, 0.f));
	GetLevel()->AddEntity(scoreCounter);
}
