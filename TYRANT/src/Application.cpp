#include <Application.h>
#include <Level.h>
#include <CollisionSystem.h>
namespace ty
{
	Application::Application(int width, int height, const std::string& title)
		: m_window(new sf::RenderWindow(sf::VideoMode(width, height), title)),
		m_CurrentLevel(nullptr),
		m_CollisionSystem(new CollisionSystem()),
		m_Paused(false)
	{
	}
	void Application::UnPause()
	{
		m_Paused = false;
	}
	void Application::Pause()
	{
		m_Paused = true;
	}
	Application::~Application()
	{
		if (m_window)
		{
			delete m_window;
		}
		UnLoadCurrentLevel();
		if (m_CollisionSystem)
		{
			delete m_CollisionSystem;
		}
	}
	void Application::Run()
	{
		m_Paused = false;
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
				m_CollisionSystem->CalculateCollision();
				if (m_CurrentLevel)
				{
					m_CurrentLevel->PostTick();
				}
			}
		}
	}

	void Application::Tick(float DeltaTime)
	{
		if (!m_Paused)
		{
			TickLevel(DeltaTime);
		}
		m_CurrentLevel->TickHud(DeltaTime);
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

	const sf::Font& Application::LoadFont(const std::string& name)
	{
		if (m_FontAssets.find(name) == m_FontAssets.end())
		{
			sf::Font font;
			if (font.loadFromFile("Resources/fonts/" + name))
			{
				m_FontAssets[name] = font;
			}
		}
		return m_FontAssets[name];
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