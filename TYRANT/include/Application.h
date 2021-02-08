#pragma once
#include <TyrantCore.h>
#include <string>
#include <SFML/Graphics.hpp>
namespace ty
{
	class TYRANT_API Application
	{
	public:
		Application(int width, int height, const std::string& title);
		virtual ~Application();
		virtual void Run();
		virtual void BeginPlay();
		virtual void Tick(float DeltaTime);
	private:
		sf::RenderWindow* m_window;
	};
}