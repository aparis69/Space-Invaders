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
    enemySpawnProbability = nullptr;

    XRES = -1;
    YRES = -1;
}

EnemyManager::EnemyManager(int xres, int yres)
{
    enemiesInProgress = vector<Enemy*>();
    timerSpawn = 0;
    spawnFrequency = 1000;
    totalProbability = 0;
    enemySpawnProbability = new int[(int)EnemyType::Insane];
    for (int i = 0 ; i < (int)EnemyType::Insane ; i++)
    {
        enemySpawnProbability[i] = (int)EnemyType::Insane - i;
        totalProbability += enemySpawnProbability[i];
    }

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
    int enemyType = getRandomEnemyType();

    enemiesInProgress.push_back(new Enemy(xSpawn, ySpawn, xSpeed, ySpeed, (EnemyType)enemyType));

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

Enemy* EnemyManager::getEnemy(int index) const 
{ 
    return enemiesInProgress.at(index); 
}

int EnemyManager::getNumberOfEnemy() const
{ 
    return enemiesInProgress.size(); 
}