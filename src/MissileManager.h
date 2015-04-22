#pragma once
#include <vector>
#include <chrono>
#include "SDLinclude.h"
#include "Missile.h"

class PhysicsManager;

class MissileManager
{
	private:	
		// Variables
		std::vector<Missile*> missileInProgress;
		float timer;

	public:
		// Constructor & Destructor
		MissileManager(void);
		~MissileManager(void);
		
		// Member functions
		void shootMissile(int xPos, int yPos);
		void updateMissileInProgress();
		void manageVectorSize(PhysicsManager* physicsManager);

		// Getter & Setter
		int getNumberOfMissile() const { return missileInProgress.size(); }
		Missile* getMissile(int index) const { return missileInProgress.at(index); }
};