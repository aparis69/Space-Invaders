#pragma once
#include <vector>
class Enemy;

class EnemyManager
{
private:
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

public:
    // Constructor & Destructor
    EnemyManager(void);
    EnemyManager(int xres, int yres);
    ~EnemyManager();

    // Member functions
    void updateEnemiesInProgress();
    void manageEnemySpawn();

    Enemy* getEnemy(int index) const { return enemiesInProgress.at(index); }

    int getNumberOfEnemy() const { return enemiesInProgress.size(); }
};