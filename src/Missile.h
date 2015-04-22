#pragma once
#include "GameObject.h"

class Missile : public GameObject
{
	private:
		int missileSpeed;

	public:
		// Constructor & Destructor
		Missile(void);
		Missile(int xPos, int yPos, int speed);
		~Missile(void) { }
};