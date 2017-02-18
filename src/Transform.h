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
	Transform();
	~Transform();

	// Getter & Setter
	int X() const;
	int Y() const;
	void setX(int);
	void setY(int);

	int XRotation() const;
	int YRotation() const;
	void setXRotation(int);
	void setYRotation(int);

	int XSize() const;
	int YSize() const;
	void setXSize(int);
	void setYSize(int);

	int XSpeed() const;
	int YSpeed() const;
	void SetXSpeed(int);
	void SetYSpeed(int);
};

#endif // !TRANSFORM_H