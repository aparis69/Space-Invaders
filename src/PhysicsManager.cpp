#include "PhysicsManager.h"

PhysicsManager::PhysicsManager(void)
{
	XRES = -1;
	YRES = -1;
}

PhysicsManager::PhysicsManager(int xres, int yres)
{
	XRES = xres;
	YRES = yres;
}

bool PhysicsManager::collideWith(int xPosM, int yPosM, int xSizeM, int ySizeM, 
								 int xPosO, int yPosO, int xSizeO, int ySizeO)
{
	if ((xPosM >= xPosO + xSizeO)
		|| (xPosM + xSizeM <= xPosO)
		|| (yPosM >= yPosO + ySizeO)
		|| (yPosM + ySizeM <= yPosO))
		return false;
	else
		return true;
}

bool PhysicsManager::isOutOfScreen(int xPos, int yPos, int xSize, int ySize)
{
	if(xPos + xSize >= XRES || yPos + YRES >= YRES || xPos <= 0 || yPos <= 0)
		return true;

	return false;
}

bool PhysicsManager::isOutOfScreen(int xPos, int yPos)
{
	if(xPos >= XRES || yPos >= YRES || xPos <= 0 || yPos <= 0)
		return true;

	return false;
}