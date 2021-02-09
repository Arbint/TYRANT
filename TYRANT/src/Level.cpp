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
	}
}