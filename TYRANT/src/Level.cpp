#include "..\include\Level.h"
#include "..\include\Level.h"
#include "Level.h"
#include "Application.h"

namespace ty
{
	Level::Level(Application* App)
		: m_app(App),
		m_Background(App->LoadTexture())
	{


	}

	void Level::BeginPlay()
	{
	
	}

	void Level::Tick(float DeltaTime)
	{
		for (auto entity : m_Entities)
		{
			entity->Tick(DeltaTime);
		}
	}

	void Level::Draw()
	{
		if (m_app && m_app->GetWindow())
		{
			DrawBackground();
			DrawEntities();
		}
	}

	void Level::DrawBackground()
	{
		m_app->GetWindow()->draw(m_Background);
	}

	void Level::DrawEntities()
	{
		for (auto entity : GetEntities())
		{
			m_app->GetWindow()->draw(entity->GetVisual());
		}
	}

	void Level::HandleInput()
	{
		for (auto entity : GetEntities())
		{
			entity->HandleInput();
		}
	}

	void Level::AddEntity(EntitySharedRef newEntity)
	{
		m_Entities.push_back(newEntity);
		if (newEntity)
		{
			newEntity->BeginPlay();
		}
	}
}