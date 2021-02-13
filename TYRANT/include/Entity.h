#pragma once
#include <TyrantCore.h>
#include <SFML/Graphics.hpp>
#include <type_traits>
#include <VisualComp.h>

namespace ty
{
	class Entity;
	typedef  std::shared_ptr<Entity> EntitySharedRef;

	class TYRANT_API Entity
	{
	public:
		Entity(class Level* app);
		virtual ~Entity();
		virtual void BeginPlay();
		virtual void HandleInput();
		virtual void Tick(float DeltaTime);
		virtual sf::FloatRect GetBound();

		//movement control
		virtual void Move(const sf::Vector2f& moveAmt);
		virtual void SetPosition(const sf::Vector2f& Loc);
		sf::Vector2f GetPosition() const { return m_location; }
		
		virtual void Rotate(float RotAmt);
		virtual void SetRotation(float rotation);
		virtual float getRotation() const { return m_rotation; }

		virtual void SetRelativeOrigin(const sf::Vector2f& origin);
		sf::Vector2f GetOrigin() const { return m_RelativeOrigin; }
		
		sf::Transform GetTransform() const;

		class Level* GetLevel();
		class Application* GetApp() { return m_app; }
		
		//The C++ you learned:
		void ConstructComponent();

		//The C++ you try to understand and write
		template<typename T>
		typename std::enable_if<!std::is_base_of<VisualComp, T>::value, std::shared_ptr<T>>::type ConstructComponent()
		
		{
			std::shared_ptr<T> newComp(new T(this));
			m_Components.push_back(newComp);
			return newComp;
		}
		
		template<typename T>
		typename std::enable_if<std::is_base_of<VisualComp, T>::value, std::shared_ptr<T>>::type ConstructComponent()
		{
			std::shared_ptr<T> newComp(new T(this));
			m_Components.push_back(newComp);
			m_VisualComponents.push_back(newComp);
			return newComp;
		}

		std::vector<std::shared_ptr<class VisualComp>> GetVisualComponents() { return m_VisualComponents; }
	private:
		void BroadCastTransformationUpdate();
	private:
		sf::Vector2f m_RelativeOrigin;
		sf::Vector2f m_location;
		float m_rotation;
		class Level* m_Level;
		class Application* m_app;
		std::vector<std::shared_ptr<class EntityComp>> m_Components;
		std::vector<std::shared_ptr<class VisualComp>> m_VisualComponents;
	};
}