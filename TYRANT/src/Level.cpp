#include "..\include\Level.h"
#include "..\include\Level.h"
#include "Level.h"
#include "Application.h"
#include "PhysicsComp.h"
#include "VisualComp.h"
#include "Hud.h"
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
			DrawHud();
		}
	}

	void Level::DrawBackground()
	{
		m_app->GetWindow()->draw(m_Background);
	}

	void Level::SetHud(std::shared_ptr<class Hud> hud)
	{
		m_Hud = hud;
	}

	void Level::DrawHud()
	{
		if (m_Hud)
		{
			m_Hud->Draw();
		}
	}

	void Level::TickHud(float DeltaTime)
	{
		if (m_Hud)
		{
			m_Hud->TickHud(DeltaTime);
		}
	}

	void Level::DrawEntities()
	{
		std::vector<std::shared_ptr<VisualComp>> AllVisuals = GetAllDrawablesSorted();
		for (int i = 0; i < AllVisuals.size(); ++i)
		{		
			GetApp()->GetWindow()->draw(AllVisuals[i]->GetVisual());
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

	void Level::PostTick()
	{
		KillPendingDestory();
	}

	void Level::KillPendingDestory()
	{
		for (int i = 0; i < m_PendingDestoryEntities.size(); i++)
		{
			for (int j = 0; j < m_Entities.size(); j++)
			{
				if (m_Entities[j].get() == m_PendingDestoryEntities[i])
				{
					m_Entities.erase(m_Entities.begin() + j);
				}
			}
		}
		m_PendingDestoryEntities.clear();
	}

	void Level::AddEntity(EntitySharedRef newEntity)
	{
		m_Entities.push_back(newEntity);
		if (newEntity)
		{
			newEntity->BeginPlay();
		}
	}

	std::vector<std::shared_ptr<class VisualComp>> Level::GetAllDrawablesSorted()
	{
		std::vector<std::shared_ptr<VisualComp>> AllVisuals;
		for (int i =0; i < m_Entities.size(); ++i)
		{
			auto visualComps = m_Entities[i]->GetVisualComponents();
			AllVisuals.insert(AllVisuals.end(), visualComps.begin(), visualComps.end());
		}
		std::sort(AllVisuals.begin(), AllVisuals.end(), VisualCompSortingFunc);
		return AllVisuals;
	}
}