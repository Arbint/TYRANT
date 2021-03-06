#include "..\include\VisualComp.h"
#include "Entity.h"
#include "Application.h"
namespace ty
{

	VisualComp::VisualComp(class Entity* Owner)
		: SpaceComp(Owner),
		m_ZOrder(0)
	{
	
	}

	void VisualComp::SetZOrder(int order)
	{
		m_ZOrder = order;
	}

	void VisualComp::SetTexture(const std::string& TexDir)
	{
		if (GetOwner())
		{
			m_Visual.setTexture(GetOwner()->GetApp()->LoadTexture(TexDir));
		}
	}
	void VisualComp::SetPosition(const sf::Vector2f& Pos)
	{
		m_Visual.setPosition(Pos);
	}
	void VisualComp::Move(const sf::Vector2f& MoveAmt)
	{
		m_Visual.move(MoveAmt);
	}
	void VisualComp::Rotate(float degree)
	{
		m_Visual.rotate(degree);
	}

	void VisualComp::SetOrigin(const sf::Vector2f& origin)
	{
		m_Visual.setOrigin(origin);
	}

	const sf::FloatRect VisualComp::GetBound() const
	{
		return m_Visual.getGlobalBounds();
	}

	void VisualComp::TransformationUpdated()
	{	
		m_Visual.setRotation(GetOwner()->getRotation() + GetLocalRotation());
		m_Visual.setPosition(CalculateGlobalLocation());
	}

	bool VisualCompSortingFunc(const std::shared_ptr<VisualComp>& lhs, const std::shared_ptr<VisualComp>& rhs)
	{
		return lhs->GetZOrder() < rhs->GetZOrder();
	}
}

