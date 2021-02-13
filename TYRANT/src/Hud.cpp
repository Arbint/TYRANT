#include "Hud.h"
#include "Level.h"
#include "Application.h"
namespace ty
{
	Hud::Hud(Level* level)
		: m_level(level)
	{
	}
	void Hud::TickHud(float DeltaTime)
	{
	}
	void Hud::Draw()
	{
	}
	sf::RenderWindow* Hud::GetWindow()
	{
		return GetLevel()->GetApp()->GetWindow();
	}
}