#pragma once
#include <vector>
#include "ObjectManager.h"
class Enemy;
class PhysicsManager;

class EnemyManager : public ObjectManager
{
private:
    // Array of enemy spawn probability, evolues during the game
    int* enemySpawnProbability;
    int totalProbability;

    // Instanciate a new enemy
    void spawnNewEnemy();
    // Determine the spawn position && speeds
    void randomSpawnPoint(int& x, int& y, int& xSpeed, int& ySpeed);
    // Get a random number from a probability array
    int getRandomEnemyType();
    // Update enemy spawn probability
    void updateProbabilities();

public:
    // Constructor & Destructor
    EnemyManager();
    ~EnemyManager();

    // Member functions
    void manageEnemySpawn();
};