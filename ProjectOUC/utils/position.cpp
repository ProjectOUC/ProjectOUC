#include "position.h"

Position::Position(const Position& other)
{
	x = other.x;
	y = other.y;
	stage = other.stage;
}

Position& Position::operator=(const Position& other)
{
	x = other.x;
	y = other.y;
	stage = other.stage;
	return *this;
}
bool Position::operator==(const Position& other) const
{
	return
		(x == other.x) &&
		(y == other.y) &&
		(stage == other.stage);
}

bool Position::operator!=(const Position& other) const
{
	return
		(x != other.x) ||
		(y != other.y) ||
		(stage != other.stage);
}

Position Position::operator-(const Position& other)
{
	x -= other.x;
	y -= other.y;
	stage -= other.stage;
	return *this;
}

Position Position::operator+(const Position& other)
{
	x += other.x;
	y += other.y;
	stage += other.stage;
	return *this;
}


void Position::set(const Position& other)
{
	x = other.x;
	y = other.y;
	stage = other.stage;
}