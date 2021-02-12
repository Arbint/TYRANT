#include <Entity.h>
#include <Application.h>
#include <Level.h>
#include <EntityComp.h>
#include <typeinfo>
#include <VisualComp.h>
#include <MathUtility.h>
namespace ty
{

	Entity::Entity(Level* level)
		:m_Level(level),
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
		for (int i = 0; i < m_Components.size(); ++i)
		{
			m_Components[i]->TickComp(DeltaTime);
		}
	}

	sf::FloatRect Entity::GetBound()
	{
		sf::FloatRect bound;
		for (int i = 0; i < m_VisualComponents.size(); ++i)
		{
			bound = bound + m_VisualComponents[i]->GetBound();
		}
		return bound;
	}

	void Entity::Move(const sf::Vector2f& moveAmt)
	{
		m_location += moveAmt;
		for (int i = 0; i < m_Components.size(); ++i)
		{
			m_Components[i]->OnwerMoved(moveAmt);
		}
	}

	void Entity::SetLocation(const sf::Vector2f& Loc)
	{
		m_location = Loc;
		for (int i = 0; i < m_Components.size(); ++i)
		{
			m_Components[i]->OwnerTeleported(Loc);
		}
	}

	Level* Entity::GetLevel()
	{
		return m_Level;
	}
}