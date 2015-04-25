#include "EnemyManager.h"
#include "Enemy.h"
#include "PhysicsManager.h"
#include <time.h>
using namespace std;

EnemyManager::EnemyManager()
{
    enemiesInProgress = vector<Enemy*>();
    timerSpawn = 0;
    spawnFrequency = 0;

    XRES = -1;
    YRES = -1;
}

EnemyManager::EnemyManager(int xres, int yres)
{
    enemiesInProgress = vector<Enemy*>();
    timerSpawn = 0;
    spawnFrequency = 1000;

    XRES = xres;
    YRES = yres;
}

EnemyManager::~EnemyManager()
{
    for (eIterator = enemiesInProgress.begin(); eIterator != enemiesInProgress.end(); eIterator++)
        delete (*eIterator);

    enemiesInProgress.clear();
}

void EnemyManager::manageEnemySpawn()
{
    if(SDL_GetTicks() < timerSpawn)
        return;
 
    spawnNewEnemy();

    timerSpawn = SDL_GetTicks() + spawnFrequency;
}

void EnemyManager::spawnNewEnemy()
{
    // Intialized in randomSpawnPoint()
    int xSpawn, ySpawn, xSpeed, ySpeed;
    randomSpawnPoint(xSpawn, ySpawn, xSpeed, ySpeed);

    enemiesInProgress.push_back(new Enemy(xSpawn, ySpawn, xSpeed, ySpeed, EnemyType::Easy));
}

void EnemyManager::randomSpawnPoint(int& x, int &y, int& xSpeed, int& ySpeed)
{
    int side = rand() % 100;
    // Left side
    if(side < 33)
    {
        y = rand() % YRES / 2;
        x = 0;
        xSpeed = -15;
        ySpeed = 0;
    }
    // Up side
    else if (side < 66)
    {
        x = rand() % XRES;
        y = 0;
        xSpeed = 0;
        ySpeed = -25;
    }
    // Right side
    else
    {
        y = rand() % YRES / 2;
        x = XRES;
        xSpeed = 15;
        ySpeed = 0;
    }
}

void EnemyManager::manageVectorSize(PhysicsManager* physicsManager)
{
    // Look at every enemy position on the screen and delete if not visible
    bool erased = false;
    for (eIterator = enemiesInProgress.begin(); eIterator != enemiesInProgress.end();)
    {
        erased = false;
        if (physicsManager->isOutOfScreen((*eIterator)->getX(), (*eIterator)->getY()))
        {
            erased = true;
            delete (*eIterator);
            eIterator = enemiesInProgress.erase(eIterator);
        }

        if (!erased)
            ++eIterator;
        else if (eIterator == enemiesInProgress.end())
            break;
    }
}

void EnemyManager::destroyEnemy(Enemy* en)
{
    for (eIterator = enemiesInProgress.begin(); eIterator != enemiesInProgress.end(); eIterator++)
    {
        if((*eIterator) == en)
        {
            delete (*eIterator);
            enemiesInProgress.erase(eIterator);
            break;
        }
    }
}