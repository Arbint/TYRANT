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
		m_app(level->GetApp()),
		m_location(0.f,0.f),
		m_rotation(0.f),
		m_RelativeOrigin(0.f,0.f)
	{
	}

	void Entity::Destory()
	{
		GetLevel()->AddPendingDestory(this);
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
		sf::FloatRect bound(GetPosition(), sf::Vector2f(0.f,0.f));
		if (m_VisualComponents.size()>0)
		{
			bound = m_VisualComponents[0]->GetBound();
			for (int i = 0; i < m_VisualComponents.size(); ++i)
			{
				bound = bound + m_VisualComponents[i]->GetBound();
			}
		}
		return bound;
	}

	void Entity::Move(const sf::Vector2f& moveAmt)
	{
		m_location += moveAmt;
		BroadCastTransformationUpdate();
	}

	void Entity::Rotate(float RotAmt)
	{
		m_rotation += RotAmt;
		BroadCastTransformationUpdate();
	}

	void Entity::SetRotation(float rotation)
	{
		m_rotation = rotation;
		BroadCastTransformationUpdate();
	}


	void Entity::SetPosition(const sf::Vector2f& Loc)
	{
		m_location = Loc;
		BroadCastTransformationUpdate();
	}

	void Entity::SetRelativeOrigin(const sf::Vector2f& origin)
	{
		m_location += origin - m_RelativeOrigin;
		m_RelativeOrigin = origin;
		BroadCastTransformationUpdate();
	}

	sf::Transform Entity::GetTransform() const
	{
		sf::Transform Trans;
		Trans.rotate(getRotation(), m_location);
		Trans.translate(m_location - m_RelativeOrigin);
		return Trans;
	}

	Level* Entity::GetLevel()
	{
		return m_Level;
	}

	void Entity::BroadCastTransformationUpdate()
	{
		for (int i = 0; i < m_Components.size(); ++i)
		{
			m_Components[i]->TransformationUpdated();
		}
	}
}