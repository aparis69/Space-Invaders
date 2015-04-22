#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	private:	
		int playerSpeed;

	public:
		// Constructor & Destructor
		Player(void);
		Player(int speed);
		~Player(void) { }

		// Getter & Setter
		inline int getSpeed() const { return playerSpeed; }
};

