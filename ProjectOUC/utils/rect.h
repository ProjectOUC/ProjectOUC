#pragma once
struct Rect
{
	Rect();
	Rect(int _left, int _bottom, int _right, int _top);
	int left, bottom, right, top;
	Rect operator=(const Rect& other);
	bool include(const int x, const int y);
	bool intersect(const Rect & other) const ;
};