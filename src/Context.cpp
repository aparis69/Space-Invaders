#include "Context.h"
#include "Player.h"
#include "Background.h"
#include "MissileManager.h"
#include "Missile.h"
#include "PhysicsManager.h"
#include "Window.h"
#include "AssetManager.h"
#include "EnemyManager.h"
#include "Enemy.h"

#include <iostream>
using namespace std;

Context::Context(void)
{
    // Init Window and Managers
    window = new Window(640, 480, 30, "Space Invaders 2");
    assetManager = new AssetManager();
    physicsManager = new PhysicsManager(Window::XRES, Window::YRES);
    missileManager = new MissileManager();
    enemyManager = new EnemyManager(Window::XRES, Window::YRES);

    // Init GameObjects in the scene
    initGameObjects();
}

Context::~Context(void)
{
    delete assetManager;
    delete window;
}

void Context::initGameObjects()
{
    player = new Player(30);
    background = new Background();
}

void Context::update(Input& in)
{
    updatePlayer(in);
    updateAI();
    updateGameObjects();
    updateBackground();

    render();
}

void Context::updatePlayer(Input& in)
{
    // Storing temporary object to improve readability
    int xSize = player->getXSize();
    int ySize = player->getYSize();
    int xPos = player->getX();
    int yPos = player->getY();

    // Move the player after checking screen bounds
    if (in.Key(SDLK_UP) && !physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(), xSize, ySize)) // Up
        player->moveY();

    if (in.Key(SDLK_DOWN) && !physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(false), xSize, ySize)) // Down
        player->moveY(false);

    if (in.Key(SDLK_LEFT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(), yPos, xSize, ySize)) // left
        player->moveX();

    if (in.Key(SDLK_RIGHT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(false), yPos, xSize, ySize)) // right
        player->moveX(false);

    if (in.Key(SDLK_SPACE)) // Shoot missile
        missileManager->shootMissile(xPos, yPos, 40, MissileType::Small);

    player->updateAnimation();
}

void Context::updateAI()
{
    enemyManager->manageEnemySpawn();
    enemyManager->updateEnemiesInProgress();
}

void Context::updateGameObjects()
{
    // Missiles in progress
    missileManager->updateMissileInProgress();
    missileManager->manageVectorSize(physicsManager);
}

void Context::updateBackground()
{
    background->updateScroll();
}

void Context::render()
{
    // Background directly blitted to make scrolling work
    SDL_Rect pos = background->getPosition();
    SDL_BlitSurface(assetManager->getSurface(background->getCurrentSpriteIndex()),
                    &pos,
                    window->getSurface(), NULL);

    // Player blitting
    window->blitSurface(assetManager->getSurface(player->getCurrentSpriteIndex()),
                        player->getX(),
                        player->getY());

    for (int i = 0; i < enemyManager->getNumberOfEnemy(); i++)
        window->blitSurface(assetManager->getSurface(enemyManager->getEnemy(i)->getCurrentSpriteIndex()),
                            enemyManager->getEnemy(i)->getX(),
                            enemyManager->getEnemy(i)->getY());

    // Missiles in progress blitting
    for (int i = 0; i < missileManager->getNumberOfMissile(); i++)
        window->blitSurface(assetManager->getSurface(missileManager->getMissile(i)->getCurrentSpriteIndex()),
                            missileManager->getMissile(i)->getX(),
                            missileManager->getMissile(i)->getY());
    // Flip screen
    window->flipScreen();
}

bool Context::gameOver()
{
    return false;
}
