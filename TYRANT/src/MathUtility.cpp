#include "MathUtility.h"
namespace sf
{
	sf::FloatRect operator+(const FloatRect& lhs, const FloatRect rhs)
	{
		float left = lhs.left < rhs.left ? lhs.left : rhs.left;
		float top = lhs.top < rhs.top ? lhs.top : rhs.top;
		float right = lhs.left + lhs.width > rhs.left + rhs.width ? lhs.left + lhs.width : rhs.left + rhs.width;
		float btm = lhs.top + lhs.height > rhs.top + rhs.height ? lhs.top + lhs.height : rhs.top + rhs.height;
		float width = right - left;
		float height = btm - top;
		return sf::FloatRect(left, top, width, height);
	}
}