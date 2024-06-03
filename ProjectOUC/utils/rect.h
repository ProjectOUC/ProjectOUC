#pragma once
struct Rect
{
	Rect();
	Rect(int _left, int _bottom, int _right, int _top);
	Rect(const Rect& other);
	int left, bottom, right, top;
	Rect operator=(const Rect& other);

	bool intersect(const Rect & other);
};