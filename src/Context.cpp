#include "Context.h"
#include "Player.h"
#include "Background.h"
#include "MissileManager.h"
#include "Missile.h"
#include "PhysicsManager.h"
#include "Window.h"
#include "AssetManager.h"
#include "Global.h"

#include <iostream>
using namespace std;

Context::Context(void)
{
    //test code blocks
    // Init Window and Managers
    window = new Window(640, 480, "Space Invaders 2");
    assetManager = new AssetManager();
    physicsManager = new PhysicsManager(window->getXRES(), window->getYRES());
    missileManager = new MissileManager();
    nbTicksLastRender = SDL_GetTicks()-16;
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
    player = new Player(10);
    background = new Background();
}

void Context::update(Input& in)
{
    int start = SDL_GetTicks();
    updatePlayer(in);
    updateAI();
    updateGameObjects();
    updateBackground();

    render();
    //cout << "Frame done in " << SDL_GetTicks() - start << endl;
    nbTicksLastRender = SDL_GetTicks();

}

void Context::updatePlayer(Input& in)
{
    // Storing temporary object to improve readability
    int xSize = player->getXSize();
    int ySize = player->getYSize();
    int xPos = player->getX();
    int yPos = player->getY();
    int localElapsedTime = elapsedTime();

    // Move the player after checking screen bounds
    if (in.Key(SDLK_UP) && !physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(localElapsedTime), xSize, ySize)) // Up
        player->moveY(localElapsedTime);

    if (in.Key(SDLK_DOWN) && !physicsManager->isOutOfScreen(xPos, yPos + player->moveValueY(localElapsedTime, false), xSize, ySize)) // Down
        player->moveY(localElapsedTime, false);

    if (in.Key(SDLK_LEFT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(localElapsedTime), yPos, xSize, ySize)) // left
        player->moveX(localElapsedTime);

    if (in.Key(SDLK_RIGHT) && !physicsManager->isOutOfScreen(xPos + player->moveValueX(localElapsedTime, false), yPos, xSize, ySize)) // right
        player->moveX(localElapsedTime, false);

    if (in.Key(SDLK_SPACE)) // Shoot missile
        missileManager->shootMissile(xPos, yPos, -5, MissileType::Small);

    player->updateAnimation();
}

void Context::updateAI()
{

}

void Context::updateGameObjects()
{
    // Missiles in progress
    missileManager->updateMissileInProgress();
    missileManager->manageVectorSize(physicsManager);
}

void Context::updateBackground()
{
    background->updateScroll(window->getYRES());
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

int Context::elapsedTime()
{
    return SDL_GetTicks() - nbTicksLastRender;
}

int Context::getLastRenderTicks() const
{
    return nbTicksLastRender;
}
