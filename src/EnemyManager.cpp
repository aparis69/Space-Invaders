#include "EnemyManager.h"
#include "Enemy.h"
#include "PhysicsManager.h"
#include "MissileManager.h"
#include "Window.h"
#include "Params.h"
#include <time.h>

EnemyManager::EnemyManager()
{
	spawnTimer = 0;
	spawnDelay = ENEMY_SPAWN_DELAY;

	// Initialized all the spawn probability variables
	totalProbability = 0;
	int numberOfEnemyType = (int)EnemyType::Insane;
	enemySpawnProbability = new int[numberOfEnemyType];
	for (int i = 0; i < numberOfEnemyType; i++)
	{
		enemySpawnProbability[i] = numberOfEnemyType - i;
		totalProbability += enemySpawnProbability[i];
	}
}

EnemyManager::~EnemyManager()
{
	delete[] enemySpawnProbability;
}

void EnemyManager::manageEnemySpawn()
{
	// Look if the timer is finished
	if (SDL_GetTicks() < spawnTimer)
		return;
	spawnNewEnemy();
	spawnTimer = SDL_GetTicks() + spawnDelay;
}

void EnemyManager::spawnNewEnemy()
{
	// These variables are intialized in randomSpawnPoint() by reference
	Vec2 pos, speed;
	randomSpawnPoint(pos, speed);
	int enemyType = getRandomEnemyType();

	objectsOnScreen.push_back(new Enemy(pos, speed, (EnemyType)enemyType));
	updateProbabilities();
}

int EnemyManager::getRandomEnemyType()
{
	int i = rand() % totalProbability + 1;
	int sum = 0;
	int i2 = 0;
	while (sum < i)
		sum += enemySpawnProbability[i2++];
	if (i2 - 1 > 0)
		return i2;
	else
		return 0;
}

void EnemyManager::updateProbabilities()
{
	totalProbability = 0;
	for (int i = 0; i < (int)EnemyType::Insane; i++)
	{
		if (rand() % 100 > 50)
			enemySpawnProbability[i] += 1;
		totalProbability += enemySpawnProbability[i];
	}
}

void EnemyManager::randomSpawnPoint(Vec2& pos, Vec2& speed)
{
	int side = rand() % 100;
	// Left side
	if (side < 33)
	{
		pos[1] = rand() % Window::YRES / 2;
		pos[0] = 0;
		speed[0] = -15;
		speed[1] = 0;
	}
	// Up side
	else if (side < 66)
	{
		pos[0] = rand() % (Window::XRES - 50);
		pos[1] = 0;
		speed[0] = 0;
		speed[1] = -45;
	}
	// Right side
	else
	{
		pos[1] = rand() % Window::YRES / 2;
		pos[0] = Window::XRES;
		speed[0] = 15;
		speed[1] = 0;
	}
}