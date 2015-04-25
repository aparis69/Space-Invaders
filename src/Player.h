#pragma once
#include "GameObject.h"

#define START_LP 5
#define X_SPAWN 250
#define Y_SPAWN 330

class Player : public GameObject
{
private:
    bool movingForward, movingBackward;
    unsigned int lifePoints;

    /** \brief Resets player's position.
     *
     * \return void
     *
     */
    void spawn();
public:
    // Constructor & Destructor
    Player(void);
    Player(float speed);

    ~Player(void)
    {
    }

    unsigned int getLifePoints() const;

    void loadSprites();

    void forward();

    void backward();

    /** \brief Stops forward of backward movement.
     *
     * \return void
     *
     */
    void stop();

    bool isMovingForward() const;

    bool isMovingBackward() const;

    ReactionTypes reactToCollision(GameObject* hitObject);

};
