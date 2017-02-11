#include "EnemyManager.h"
#include "Enemy.h"
#include "PhysicsManager.h"
#include "Window.h"
#include <time.h>
using namespace std;

EnemyManager::EnemyManager()
{
	enemiesOnScreen = vector<Enemy*>();
	timerSpawn = 0;
	spawnFrequency = 1000;
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
    for (eIt = enemiesOnScreen.begin(); eIt != enemiesOnScreen.end(); eIt++)
        delete (*eIt);

    enemiesOnScreen.clear();
}

void EnemyManager::manageEnemySpawn()
{
    // Look if the timer is finished
    if(SDL_GetTicks() < timerSpawn)
        return;

    spawnNewEnemy();
    timerSpawn = SDL_GetTicks() + spawnFrequency;
}

void EnemyManager::spawnNewEnemy()
{
    // These variables are intialized in randomSpawnPoint() by references
    int xSpawn, ySpawn, xSpeed, ySpeed;
    randomSpawnPoint(xSpawn, ySpawn, xSpeed, ySpeed);
    int enemyType = getRandomEnemyType();

    enemiesOnScreen.push_back(new Enemy(xSpawn, ySpawn, xSpeed, ySpeed, (EnemyType)enemyType));
    updateProbabilities();
}

int EnemyManager::getRandomEnemyType()
{
    int i = rand() % totalProbability + 1;
    int sum = 0;
    int i2 = 0;

    while (sum < i)
        sum += enemySpawnProbability[i2++];

    if(i2 - 1 > 0)
        return i2;
    else
        return 0;
}

void EnemyManager::updateProbabilities()
{
    totalProbability = 0;
    for (int i = 0 ; i < (int)EnemyType::Insane ; i++)
    {
        if(rand() % 100 > 50)
            enemySpawnProbability[i] += 1;

        totalProbability += enemySpawnProbability[i];
    }
}

void EnemyManager::randomSpawnPoint(int& x, int &y, int& xSpeed, int& ySpeed)
{
    int side = rand() % 100;
    // Left side
    if(side < 33)
    {
        y = rand() % Window::YRES / 2;
        x = 0;
        xSpeed = -15;
        ySpeed = 0;
    }
    // Up side
    else if (side < 66)
    {
        x = rand() % Window::XRES;
        y = 0;
        xSpeed = 0;
        ySpeed = -25;
    }
    // Right side
    else
    {
        y = rand() % Window::YRES / 2;
        x = Window::XRES;
        xSpeed = 15;
        ySpeed = 0;
    }
}

void EnemyManager::manageVectorSize(PhysicsManager* physicsManager)
{
    // Look at every enemy position on the screen and delete if not visible
    bool erased = false;
    for (eIt = enemiesOnScreen.begin(); eIt != enemiesOnScreen.end();)
    {
        erased = false;
        if (physicsManager->isOutOfScreen((*eIt)->getTransform().X(), (*eIt)->getTransform().Y()))
        {
            erased = true;
            delete (*eIt);
            eIt = enemiesOnScreen.erase(eIt);
        }

        if (!erased)
            ++eIt;
        else if (eIt == enemiesOnScreen.end())
            break;
    }
}

void EnemyManager::destroyEnemy(Enemy* en)
{
    // Search for the enemy en, delete it and return
    for (eIt = enemiesOnScreen.begin(); eIt != enemiesOnScreen.end(); eIt++)
    {
        if((*eIt) == en)
        {
            delete (*eIt);
            enemiesOnScreen.erase(eIt);
            break;
        }
    }
}

Enemy* EnemyManager::getEnemy(int index) const 
{ 
    return enemiesOnScreen.at(index); 
}

int EnemyManager::getEnemyCount() const
{ 
    return enemiesOnScreen.size(); 
}