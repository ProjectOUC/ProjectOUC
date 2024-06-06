#include "rect.h"
<<<<<<< HEAD
=======

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
	return x >= left && x <= right && y >= bottom && y <= top;
}
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
