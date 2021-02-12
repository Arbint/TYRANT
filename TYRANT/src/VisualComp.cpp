#include "..\include\VisualComp.h"
#include "Entity.h"
#include "Application.h"
namespace ty
{

	VisualComp::VisualComp(Entity* Owner)
		: EntityComp(Owner)
	{

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
}