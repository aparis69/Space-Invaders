#pragma once
#include "GameObject.h"
#include "SDLinclude.h"

#define SPEED_ADJUST 100

class Background : public GameObject
{
private:
    SDL_Rect scroll;
    int scrollSpeed;
    bool speedingUp, slowingDown;
    // Ticks when background last scrolled.
    Uint32 lastScroll; 

public:
    // Constructor & Destructor
    Background(int scrollSpeed);
    ~Background(void);

    // Member functions
    void updateScroll();
    void loadSprites();
    ReactionTypes reactToCollision(GameObject* hitObject) { return ReactionTypes::Nothing; }

    // Getter & Setter
    SDL_Rect getPosition();

    /** \brief Resets scroll Rect after having reached end of screen.
     *
     * \return void
     *
     */
    void resetScroll();

    /** \brief Speeds up the speed when player is moving foward.
     *
     * \return void
     *
     */
    void speedUp();

    /** \brief Slows scrolling down when player stops moving foward.
     *
     * \return void
     *
     */
    void slowDown();

    /** \brief Back to normal speed.
     *
     * \return void
     *
     */
    void idle();
};