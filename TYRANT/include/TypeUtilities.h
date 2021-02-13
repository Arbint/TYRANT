#pragma once
#include <type_traits>
#include <typeinfo>
#include <iostream>
namespace ty {
	//will count child class
	template<typename Base, typename T>
	bool IsOfType(const T* t)
	{
		bool same = (typeid(Base) == typeid(*t));
		bool child = std::is_base_of<Base, T>::value;
		
		return same || child;
	}
}