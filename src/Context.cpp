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

// Init static array of gameObjects
vector<GameObject*> Context::gameObjects = vector<GameObject*> ();

Context::Context(void)
{
    // Init Window and Managers
    window = new Window(640, 480, 120, "Space Invaders 2");
    assetManager = new AssetManager();
    physicsManager = new PhysicsManager(Window::XRES, Window::YRES);
    missileManager = new MissileManager();
    enemyManager = new EnemyManager(Window::XRES, Window::YRES);

    // Init GameObjects in the scene
    initGameObjects();
}

Context::~Context(void)
{
    gameObjects.clear();

    delete player;
    delete background;
    delete missileManager;
    delete physicsManager;
    delete enemyManager;
    delete assetManager;
    delete window;
}

void Context::initGameObjects()
{
    player = new Player(50);
    background = new Background(300);
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
    bool wasForward = player->isMovingForward(), wasBackward = player->isMovingBackward();

    if(!in.Key(SDLK_UP) && !in.Key(SDLK_DOWN))
        player->stop();

    // Move the player after checking screen bounds
    if (in.Key(SDLK_UP)) // Up
    {
        if(!physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(), xSize, ySize))
        {
            player->moveY();
            player->forward();
        }
        else
            player->stop();
    }


    if (in.Key(SDLK_DOWN)) // Down
    {
        if(!physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(false), xSize, ySize))
        {
            player->moveY(false);
            player->backward();
        }
        else
            player->stop();
    }

    if (in.Key(SDLK_LEFT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(), yPos, xSize, ySize)) // left
        player->moveX();

    if (in.Key(SDLK_RIGHT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(false), yPos, xSize, ySize)) // right
        player->moveX(false);

    if (in.Key(SDLK_SPACE)) // Shoot missile
        missileManager->shootMissile(xPos, yPos, 40, MissileType::Small);

    if(!wasForward && player->isMovingForward())
        background->speedUp();
    else if(!wasBackward && player->isMovingBackward())
        background->slowDown();
    else if((wasForward && !player->isMovingForward()) || (wasBackward && !player->isMovingBackward()))
        background->idle();

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
    SDL_Surface* backgroundSurface = assetManager->getSurface(background->getCurrentSpriteIndex());
    if(pos.y >= 0)
        SDL_BlitSurface(backgroundSurface,
                        &pos,
                        window->getSurface(), NULL);
    else
    {
        pos.h = pos.h + pos.y;
        int lastY = pos.y;
        pos.y = 0;
        SDL_BlitSurface(backgroundSurface,
                        &pos,
                        window->getSurface(), NULL);
        SDL_Rect dst;
        dst.x = 0;
        dst.y = Window::YRES - lastY;
        pos.y = 960 + lastY;
        pos.h = lastY*-1;
        SDL_BlitSurface(backgroundSurface,
                        &pos,
                        window->getSurface(), &dst);
        background->resetScroll();
    }

    // Player blitting
    window->blitSurface(assetManager->getSurface(player->getCurrentSpriteIndex()),
                        player->getX(),
                        player->getY());

    // Enemy blitting
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

// Static member functions
void Context::addGameObject(GameObject* object)
{
    gameObjects.push_back(object);
}

void Context::deleteGameObject(GameObject* object)
{
    vector<GameObject*>::iterator it;
    for (it = gameObjects.begin() ; it != gameObjects.end() ; it++)
    {
        if((*it) == object)
        {
            gameObjects.erase(it);
            return;
        }
    }
}

vector<GameObject*>::iterator Context::getGameObjectIterator(int i)
{
    vector<GameObject*>::iterator it = gameObjects.begin();
    std::advance(it, i);
    
    return it;
}

int Context::getGameObjectCount()
{ 
    return gameObjects.size(); 
}