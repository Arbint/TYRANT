#include "..\include\Application.h"
#include "..\include\Application.h"
#include "..\include\Application.h"
#include "..\include\Application.h"
#include "..\include\Application.h"
#include <Application.h>
#include <Level.h>
namespace ty
{
	Application::Application(int width, int height, const std::string& title)
		: m_window(new sf::RenderWindow(sf::VideoMode(width, height), title)),
		m_CurrentLevel(nullptr)

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
		if (m_CurrentLevel)
		{
			m_CurrentLevel->BeginPlay();
		}

		float previousFrameTime = m_clock.getElapsedTime().asSeconds();
		if (m_window)
		{
			while (m_window->isOpen())
			{
				HandleWindowEvents();
				float currentTime = m_clock.getElapsedTime().asSeconds();
				float DeltaTime = currentTime - previousFrameTime;
				previousFrameTime = currentTime;
				Tick(DeltaTime);
				if (m_CurrentLevel)
				{
					m_CurrentLevel->PostTick();
				}
			}
		}
	}

	void Application::Tick(float DeltaTime)
	{
		TickLevel(DeltaTime);

		m_window->clear();
		if (m_CurrentLevel)
		{
			m_CurrentLevel->Draw();
		}
		m_window->display();
	}
	
	void Application::TickLevel(float DeltaTime)
	{
		if (m_CurrentLevel)
		{
			m_CurrentLevel->Tick(DeltaTime);
		}
	}

	void Application::LoadLevel(Level* newLevel)
	{
		UnLoadCurrentLevel();
		m_CurrentLevel = newLevel;
		Run();
	}

	const sf::Texture& Application::LoadTexture(const std::string& name)
	{
		if (m_textureAssets.find(name) == m_textureAssets.end())
		{
			sf::Texture tx;
			if (tx.loadFromFile("Resources/textures/"+name))
			{
				m_textureAssets[name] = tx;
			}
		}
		return m_textureAssets[name];
	}
	
	void Application::HandleWindowEvents()
	{
		sf::Event event;
		while (m_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_window->close();
			}
			if (event.type==sf::Event::KeyPressed)
			{
				HandleInput();
			}
		}
	}

	void Application::HandleInput()
	{
		if (m_CurrentLevel)
		{
			m_CurrentLevel->HandleInput();
		}
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