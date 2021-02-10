#include <Entity.h>
#include <Application.h>
#include <Level.h>
namespace ty
{

	Entity::Entity(Level* level)
		:m_Level(level),
		m_Visual(),
		m_app(level->GetApp())
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
		if (m_Level)
		{
			m_Visual.setTexture(m_Level->GetApp()->LoadTexture(visualName));
		}
	}

	Level* Entity::GetLevel()
	{
		return m_Level;
	}

}