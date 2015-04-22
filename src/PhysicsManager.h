#pragma once
class PhysicsManager
{
	private:
		int XRES;
		int YRES;

	public:
		// Constructor & Destructor
		PhysicsManager(void);
		PhysicsManager(int xres, int yres);
		~PhysicsManager(void) { }

		// Member functions
		bool collideWith(int xPosM, int yPosM, int xSizeM, int ySizeM, int xPosO, int yPosO, int xSizeO, int ySizeO);
		bool isOutOfScreen(int xPos, int yPos, int xSize, int ySize);
		bool isOutOfScreen(int xPos, int yPos);

		// Getter & Setter
		inline void setXRES(int xres) { XRES = xres; }
		inline void setYRES(int yres) { YRES = yres; }
};

