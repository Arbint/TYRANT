#pragma once
#include "SpaceComp.h"
#include <Entity.h>
#include <iostream>
ty::SpaceComp::SpaceComp(class Entity* Owner)
	: EntityComp(Owner),
	m_localLocation(0.f, 0.f),
	m_localRotation(0.f)
{

}

void ty::SpaceComp::SetLocalLocation(const sf::Vector2f& loc)
{
	m_localLocation = loc;
	TransformationUpdated();
}

void ty::SpaceComp::SetLocalRotation(float rot)
{
	m_localRotation = rot;
	std::cout << m_localRotation << std::endl;
	TransformationUpdated();
}

sf::Vector2f ty::SpaceComp::GetLocationLocation()
{
	return m_localLocation;
}

float ty::SpaceComp::GetLocalRotation()
{
	return m_localRotation;
}

sf::Vector2f ty::SpaceComp::CalculateGlobalLocation()
{
	return GetOwner()->GetTransform().transformPoint(m_localLocation);
}
