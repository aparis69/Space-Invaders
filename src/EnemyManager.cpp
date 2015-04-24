#include "EnemyManager.h"
#include "Enemy.h"
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

}

void EnemyManager::updateEnemiesInProgress()
{
    for (unsigned int i = 0; i < enemiesInProgress.size(); i++)
    {
        enemiesInProgress.at(i)->move();
        enemiesInProgress.at(i)->updateAnimation();
    }
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