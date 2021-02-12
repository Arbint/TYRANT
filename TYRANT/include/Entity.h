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
		virtual void Move(const sf::Vector2f& moveAmt);
		virtual void SetLocation(const sf::Vector2f& Loc);
		sf::Vector2f GetPosition() const { return m_location; }

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
		sf::Vector2f m_location;
		class Level* m_Level;
		class Application* m_app;
		std::vector<std::shared_ptr<class EntityComp>> m_Components;
		std::vector<std::shared_ptr<class VisualComp>> m_VisualComponents;
	};
}