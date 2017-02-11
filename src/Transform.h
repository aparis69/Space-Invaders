#pragma once

class Transform
{
private:
	// Current positions of object on screen (pixels)
	int x, y;
	// Size of the game object
	int xSize, ySize;
	// Speeds of the object in pixels/ms
	int xSpeed, ySpeed;

public:
	// Constructors & Destructor
	Transform();
	~Transform();

	// Getter & Setter
	int X() const;
	int Y() const;
	void setX(int);
	void setY(int);

	int XSize() const;
	int YSize() const;
	void setXSize(int);
	void setYSize(int);

	int XSpeed() const;
	int YSpeed() const;
	void SetXSpeed(int);
	void SetYSpeed(int);
};