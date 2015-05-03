#pragma once
#include <vector>
class Enemy;
class PhysicsManager;

class EnemyManager
{
private:
    // Difficulty of the game, increase at every frame
    float difficulty;
    int* enemySpawnProbability;
    int totalProbability;

    // Timer regulating the spawn frequency
    float timerSpawn;
    // An enemy will be spawn every <spawnFrequency> second
    float spawnFrequency;
    std::vector<Enemy*> enemiesInProgress;
    std::vector<Enemy*>::iterator eIterator;

    int XRES, YRES;

    // Instanciate a new enemy
    void spawnNewEnemy();
    // Determine the spawn position
    void randomSpawnPoint(int& x, int& y, int& xSpeed, int& ySpeed);
    // Get a random number from a probability array
    int getRandomEnemyType();
    // Update enemy spawn probability
    void updateProbabilities();

public:
    // Constructor & Destructor
    EnemyManager(void);
    EnemyManager(int xres, int yres);
    ~EnemyManager();

    // Member functions
    void manageEnemySpawn();
    void manageVectorSize(PhysicsManager* physicsManager);

    // Erase the object in the vector<Enemy*>
    void destroyEnemy(Enemy* en);

    Enemy* getEnemy(int index) const;
    int getNumberOfEnemy() const;
};