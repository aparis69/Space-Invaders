#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vec2.h"

class Transform
{
private:
	// Current positions of object on screen (pixels)
	Vec2 position;
	// Current rotation
	Vec2 rotation;
	// Size of the game object
	Vec2 size;
	// Speeds of the object in pixels/ms
	Vec2 speed;

public:
	// Constructors & Destructor
	Transform(Vec2);
	Transform(Vec2, Vec2);
	Transform();
	~Transform();

	// Operator overloading
	bool operator==(const Transform&) const;

	// Getter & Setter
	Vec2 getPosition() const;
	void setPosition(Vec2);
	int X() const;
	int Y() const;
	void setX(int);
	void setY(int);

	Vec2 getRotation() const;
	void setRotation(Vec2);
	int XRotation() const;
	int YRotation() const;
	void setXRotation(int);
	void setYRotation(int);

	Vec2 getSize() const;
	void setSize(Vec2);
	int XSize() const;
	int YSize() const;
	void setXSize(int);
	void setYSize(int);

	Vec2 getSpeed() const;
	void setSpeed(Vec2);
	int XSpeed() const;
	int YSpeed() const;
	void SetXSpeed(int);
	void SetYSpeed(int);
};

#endif // !TRANSFORM_H