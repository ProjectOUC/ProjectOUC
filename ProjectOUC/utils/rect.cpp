#include "rect.h"

Rect::Rect()
{
	left = right = bottom = top = 0;
}

Rect::Rect(int _left, int _bottom, int _right, int _top)
{
	left = _left;
	bottom = _bottom;
	right = _right;
	top = _top;
}

Rect Rect::operator=(const Rect& other)
{
	left = other.left;
	right = other.right;
	bottom = other.bottom;
	top = other.top;
	return *this;
}

bool Rect::include(const int x, const int y)
{
	return y >= left && y <= right && x >= bottom && x <= top;
}