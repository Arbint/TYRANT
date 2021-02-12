#pragma once
#include <EntityComp.h>
#include <SFML/Graphics.hpp>
namespace ty
{
	class TYRANT_API VisualComp : public EntityComp 
	{
	public:
		VisualComp(class Entity* Owner);
		void SetZOrder(int order);
		void SetTexture(const std::string& TexDir);
		void SetPosition(const sf::Vector2f& Pos);
		void Move(const sf::Vector2f& MoveAmt);
		void Rotate(float degree);
		void SetOrigin(const sf::Vector2f& origin);
		const sf::FloatRect GetBound() const override;

		virtual void OnwerMoved(const sf::Vector2f& amt) override;
		virtual void OwnerRotated(float amt) override;
		virtual void OwnerTeleported(const sf::Vector2f& loc) override;

		const sf::Sprite& GetVisual() const { return m_Visual; }
		sf::Sprite& GetVisual() { return m_Visual; }

		//operators
		friend bool operator>(const VisualComp& lhs, const VisualComp& rhs);
		friend bool operator==(const VisualComp& lhs, const VisualComp& rhs);
		friend bool operator<(const VisualComp& lhs, const VisualComp& rhs);
		friend bool operator<=(const VisualComp& lhs, const VisualComp& rhs);
		friend bool operator>=(const VisualComp& lhs, const VisualComp& rhs);

	private:
		sf::Sprite m_Visual;
		int m_ZOrder;
	};
}
