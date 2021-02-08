#include <Application.h>
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
	}
	void Application::Run()
	{
		BeginPlay();
		if (m_window)
		{
			while (m_window->isOpen())
			{
				sf::Event event;
				m_window->pollEvent(event);
				if (event.type == sf::Event::Closed)
				{
					m_window->close();
				}
				Tick(0.1);
			}
		}
	}
	void Application::BeginPlay()
	{
	}
	void Application::Tick(float DeltaTime)
	{
		m_window->clear();
		m_window->display();
	}
}