#include "Transform.h"

// Constructors & Destructor
Transform::Transform()
{
	x = y = 0;
	xSize = ySize = 0;
	xSpeed = ySpeed = 0;
}

Transform::~Transform()
{

}


// Getter & Setter
int Transform::X() const
{
	return x;
}

int Transform::Y() const
{
	return y;
}

void Transform::setX(int v)
{
	x = v;
}

void Transform::setY(int v)
{
	y = v;
}

int Transform::XSize() const
{
	return xSize;
}

int Transform::YSize() const
{
	return ySize;
}

void Transform::setXSize(int v)
{
	xSize = v;
}

void Transform::setYSize(int v)
{
	ySize = v;
}

int Transform::XSpeed() const
{
	return xSpeed;
}

int Transform::YSpeed() const
{
	return ySpeed;
}

void Transform::SetXSpeed(int v)
{
	xSpeed = v;
}

void Transform::SetYSpeed(int v)
{
	ySpeed = v;
}