#pragma once
#include <EntityComp.h>
#include <SFML/Graphics.hpp>
namespace ty
{
	class TYRANT_API SpaceComp : public EntityComp
	{
	public:
		SpaceComp(class Entity* Owner);
		void SetLocalLocation(const sf::Vector2f& loc);
		void SetLocalRotation(float rot);
		sf::Vector2f GetLocationLocation();
		float GetLocalRotation();
		sf::Vector2f CalculateGlobalLocation();
	private:
		sf::Vector2f m_localLocation;
		float m_localRotation;
	};
}