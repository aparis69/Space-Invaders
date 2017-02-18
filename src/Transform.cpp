#include "Transform.h"

// Constructors & Destructor
Transform::Transform()
{
}

Transform::~Transform()
{
}


// Getter & Setter
int Transform::X() const
{
	return position.getX();
}

int Transform::Y() const
{
	return position.getY();
}

void Transform::setX(int v)
{
	position[0] = v;
}

void Transform::setY(int v)
{
	position[1] = v;
}

int Transform::XRotation() const
{
	return rotation.getX();
}

int Transform::YRotation() const
{
	return rotation.getY();
}

void Transform::setXRotation(int x)
{
	rotation[0] = x;
}

void Transform::setYRotation(int y)
{
	rotation[1] = y;
}

int Transform::XSize() const
{
	return size.getX();
}

int Transform::YSize() const
{
	return size.getY();
}

void Transform::setXSize(int v)
{
	size[0] = v;
}

void Transform::setYSize(int v)
{
	size[1] = v;
}

int Transform::XSpeed() const
{
	return speed.getX();
}

int Transform::YSpeed() const
{
	return speed.getY();
}

void Transform::SetXSpeed(int v)
{
	speed[0] = v;
}

void Transform::SetYSpeed(int v)
{
	speed[1] = v;
}