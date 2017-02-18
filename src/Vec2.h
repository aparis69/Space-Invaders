#ifndef VEC2_H
#define VEC2_H

class Vec2
{
private:
	int c[2];

public:
	// Constructor & Destructor
	Vec2();
	Vec2(int, int);
	~Vec2();

	// Member function
	int& operator[](int);
	const int& getX() const;
	const int& getY() const;
};

#endif // !VEC2_H