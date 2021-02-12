#pragma once
#include <EntityComp.h>
#include <SFML/Graphics.hpp>
namespace ty
{
	class VisualComp : public EntityComp 
	{
	public:
		VisualComp(class Entity* Owner);
		void SetTexture(const std::string& TexDir);
		void SetPosition(const sf::Vector2f& Pos);
		void Move(const sf::Vector2f& MoveAmt);
		void Rotate(float degree);
		const sf::Sprite& GetVisual() const { return m_Visual; }
	private:
		sf::Sprite m_Visual;
	};
}