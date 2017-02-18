#include "Vec2.h"

Vec2::Vec2()
{
	c[0] = c[1] = 0;
}

Vec2::Vec2(int x, int y)
{
	c[0] = x;
	c[1] = y;
}

Vec2::~Vec2()
{
}

int& Vec2::operator[](int i)
{
	return c[i];
}

const int & Vec2::getX() const
{
	return c[0];
}

const int & Vec2::getY() const
{
	return c[1];
}