#include "pipeGenerator.h"
#include "Pipe.h"
#include "Level.h"
#include <random>
#include <time.h>
#include <Application.h>
#include <iostream>
PipeGenerator::PipeGenerator(ty::Level* level)
	: Entity(level),
	m_SpawnIntervalSeconds(5),
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
	/*
	ty::EntitySharedRef TopPipe(new Pipe(GetLevel()));
	ty::EntitySharedRef BtmPipe(new Pipe(GetLevel()));
	GetLevel()->AddEntity(TopPipe);
	GetLevel()->AddEntity(BtmPipe);
	int PipeHeight = TopPipe->GetBound().height;
	TopPipe->.setOrigin(TopPipe->GetBound().width/2, TopPipe->GetBound().height/2);
	BtmPipe->GetVisual().setOrigin(TopPipe->GetVisual().getOrigin());
	TopPipe->GetVisual().setRotation(180);
	float PipeStartXLocation = GetApp()->GetWindow()->getSize().x + TopPipe->GetBound().width/2;
	float TopPipeYLocation = rand()%(PipeHeight/2);
	float BtmPipeYLocation = TopPipeYLocation + m_Gap;
	TopPipe->SetLocation(sf::Vector2f(PipeStartXLocation, TopPipeYLocation));
	BtmPipe->SetLocation(sf::Vector2f(PipeStartXLocation, BtmPipeYLocation));
	*/
}
