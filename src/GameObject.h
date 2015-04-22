#pragma once
#include "Sprite.h"

class GameObject
{
	protected:
		Sprite* sprite;
		int currentSprite;
		int numberOfSprite;

	public:
		// Constructor & Destructor
		GameObject(void);
		virtual ~GameObject(void);

		// Member functions
		virtual void updateAnimation();

		// Getter & Setter
		virtual Sprite* getSprite() const { return sprite; }
		virtual inline Sprite* getCurrentSprite() const { return &sprite[currentSprite]; }
		virtual inline Sprite* getSprite(int index) { return &sprite[index]; }
		// Get the xPos of the current Sprite
		virtual inline int getXPos() const { return sprite[currentSprite].GetX(); }
		// Get the yPos of the current Sprite
		virtual inline int getYPos() const { return sprite[currentSprite].GetY(); }
};