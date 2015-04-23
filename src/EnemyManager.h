#pragma once
#include <vector>
class Enemy;

class EnemyManager
{
    private:
        std::vector<Enemy*> enemiesInProgress;

    public:
        // Constructor & Destructor
        EnemyManager(void);
        ~EnemyManager();

        // Member functions
};