#include "Transform.h"

Transform::Transform(Vec2 p)
{
	position = p;
}

Transform::Transform(Vec2 p, Vec2 s)
{
	position = p;
	size = s;
}

// Constructors & Destructor
Transform::Transform()
{
}

Transform::~Transform()
{
}

bool Transform::operator==(const Transform & t) const
{
	if (t.position == position &&
		t.rotation == rotation &&
		t.size == size &&
		t.speed == speed)
		return true;
	return false;
}


// Getter & Setter
Vec2 Transform::getPosition() const
{
	return position;
}

void Transform::setPosition(Vec2 p)
{
	position = p;
}

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

Vec2 Transform::getRotation() const
{
	return rotation;
}

void Transform::setRotation(Vec2 r)
{
	rotation = r;
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

Vec2 Transform::getSize() const
{
	return size;
}

void Transform::setSize(Vec2 s)
{
	size = s;
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

Vec2 Transform::getSpeed() const
{
	return speed;
}

void Transform::setSpeed(Vec2 s)
{
	speed = s;
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