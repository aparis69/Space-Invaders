#pragma once
#include "Input.h"

#include <vector>
#include <SDL_ttf.h>

class Window;
class AssetManager;
class MissileManager;
class PhysicsManager;
class EnemyManager;
class Player;
class Background;
class GameObject;

class Context
{
private:
    // Static array of all the gameObject in the scene
    static std::vector<GameObject*> gameObjects;

    // Managers
    AssetManager* assetManager;
    MissileManager* missileManager;
    PhysicsManager* physicsManager;
    EnemyManager* enemyManager;

    // Unique Objects
    Player* player;
    unsigned int lastPlayerLifePoints;
    Background* background;
    Window* window;

    TTF_Font* font;
    SDL_Color fontColor;
    SDL_Surface* lifePointsSurface;

    // Private functions
    void initGameObjects();
    void updateBackground();
    void updatePlayer(Input& in);
    void updateAI();
    void updateGameObjects();

public:
    // Constructor & Destructor
    Context(void);
    ~Context(void);

    // Member functions
    void update(Input& in);
    void render();

    // Getter & Setter
    bool gameOver();

    // Static function, interact with the gameObject array
    static void addGameObject(GameObject* object);
    static void deleteGameObject(GameObject* object);
    static std::vector<GameObject*>::iterator getGameObjectIterator(int i);
    static int getGameObjectCount();
};
