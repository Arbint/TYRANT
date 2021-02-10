#include <Entity.h>
#include <Application.h>
#include <Level.h>
#include <EntityComp.h>
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
		for (auto comp : m_Components)
		{
			comp->TickComp(DeltaTime);
		}
	}

	void Entity::SetVisual(const std::string& visualName)
	{
		if (m_Level)
		{
			m_Visual.setTexture(m_Level->GetApp()->LoadTexture(visualName));
		}
	}

	void Entity::Move(const sf::Vector2f& moveAmt)
	{
		m_Visual.move(moveAmt);
	}

	void Entity::SetLocation(const sf::Vector2f& Loc)
	{
		GetVisual().setPosition(Loc);
	}

	Level* Entity::GetLevel()
	{
		return m_Level;
	}

}