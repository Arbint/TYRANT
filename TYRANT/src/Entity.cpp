#include <Entity.h>
#include <Application.h>
namespace ty
{

	Entity::Entity(class Application* app)
		:m_app(app),
		m_Visual()
	{

	}

	Entity::~Entity()
	{

	}

	void Entity::BeginPlay()
	{

	}

	void Entity::HandleInput()
	{
		
	}

	void Entity::Tick(float DeltaTime)
	{

	}

	void Entity::SetVisual(const std::string& visualName)
	{
		if (m_app)
		{
			m_Visual.setTexture(m_app->LoadTexture(visualName));
		}
	}

}