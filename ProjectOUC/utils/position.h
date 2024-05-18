#pragma once
struct Position
{
	Position() : stage(0), x(0), y(0) {}
	Position(int _stage, int _x, int _y): stage(_stage), x(_x), y(_y) {}
	Position(const Position& other);
	
	Position& operator=(const Position& other);
	bool operator==(const Position& other) const;
	bool operator!=(const Position& other) const;
	Position operator-(const Position& other);
	Position operator+(const Position& other);

	void set(const Position& other);

	int stage, x, y;

};

