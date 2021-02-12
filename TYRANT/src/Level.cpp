#include "..\include\Level.h"
#include "..\include\Level.h"
#include "Level.h"
#include "Application.h"
#include "PhysicsComp.h"
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
		for (int i = 0; i < m_Entities.size(); ++i)
		{
			if (m_Entities[i])
			{
				m_Entities[i]->Tick(DeltaTime);
			}
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
		for (int i = 0; i < m_Entities.size(); ++i)
		{
			if (m_Entities[i])
			{
				GetApp()->GetWindow()->draw(m_Entities[i]->GetVisual());
			}
		}
	}

	void Level::HandleInput()
	{
		for (int i = 0; i < m_Entities.size(); ++i)
		{
			if (m_Entities[i])
			{
				m_Entities[i]->HandleInput();
			}
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