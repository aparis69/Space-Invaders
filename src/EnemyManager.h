#pragma once
#include <vector>
class Enemy;
class PhysicsManager;

class EnemyManager
{
private:
    // Array of enemy spawn probability, evolues during the game
    int* enemySpawnProbability;
    int totalProbability;
    // Timer regulating the spawn frequency
    float timerSpawn;
    // An enemy will be spawn every <spawnFrequency> second
    float spawnFrequency;
    // vector and iterator for interacting with enemies in the scene
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
    // Delete enemies out of screen
    void manageVectorSize(PhysicsManager* physicsManager);
    // Erase the object in the vector<Enemy*>
    void destroyEnemy(Enemy* en);

    // Getter & Setter
    Enemy* getEnemy(int index) const;
    int getNumberOfEnemy() const;
};