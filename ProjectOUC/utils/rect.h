#pragma once
<<<<<<< HEAD
class rect
{
};

=======
struct Rect
{
	Rect();
	Rect(int _left, int _bottom, int _right, int _top);
	int left, bottom, right, top;
	Rect operator=(const Rect& other);
	bool include(const int x, const int y);
	bool intersect(const Rect & other) const ;
};
>>>>>>> ebf75e24e5d42300b2e6462fb013eaafc4b87d1c
