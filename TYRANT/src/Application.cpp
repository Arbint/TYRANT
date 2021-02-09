#include "..\include\Application.h"
#include "..\include\Application.h"
#include <Application.h>
#include <Level.h>
namespace ty
{
	Application::Application(int width, int height, const std::string& title)
		: m_window(new sf::RenderWindow(sf::VideoMode(width, height), title))
	{
	}
	Application::~Application()
	{
		if (m_window)
		{
			delete m_window;
		}
		UnLoadCurrentLevel();
	}
	void Application::Run()
	{

		float previousFrameTime = m_clock.getElapsedTime().asSeconds();
		if (m_window)
		{
			while (m_window->isOpen())
			{
				float currentTime = m_clock.getElapsedTime().asSeconds();
				float DeltaTime = currentTime - previousFrameTime;
				previousFrameTime = currentTime;

				sf::Event event;
				m_window->pollEvent(event);
				if (event.type == sf::Event::Closed)
				{
					m_window->close();
				}
				
				Tick(DeltaTime);
			}
		}
	}

	void Application::Tick(float DeltaTime)
	{
		if (m_CurrentLevel)
		{
			m_CurrentLevel->Tick(DeltaTime);
		}
		m_window->clear();
		m_window->display();
	}
	void Application::LoadLevel(Level* newLevel)
	{
		UnLoadCurrentLevel();
		m_CurrentLevel = newLevel;
		Run();
	}
	void Application::UnLoadCurrentLevel()
	{
		if (m_CurrentLevel)
		{
			delete m_CurrentLevel;
			m_CurrentLevel = nullptr;
		}
	}
}