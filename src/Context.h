#pragma once
#include "Input.h"

class Window;
class AssetManager;
class MissileManager;
class PhysicsManager;
class Player;
class Background;

class Context
{
private:
    Window* window;

    // Managers
    AssetManager* assetManager;
    MissileManager* missileManager;
    PhysicsManager* physicsManager;

    // Unique Objects
    Player* player;
    Background* background;

    //Number of ticks when last rendered
    int nbTicksLastRender;

    // Private functions
    void initGameObjects();
    void updateBackground();
    void updatePlayer(Input& in);
    void updateAI();
    void updateGameObjects();

    //Elapsed ticks since last render
    int elapsedTime();

public:
    // Constructor & Destructor
    Context(void);
    ~Context(void);

    // Member functions
    void update(Input& in);
    void render();

    // Getter & Setter
    bool gameOver();

    int getLastRenderTicks() const;
};
