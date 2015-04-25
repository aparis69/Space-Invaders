#pragma once
#include "GameObject.h"

#define START_LP 5

class Player : public GameObject
{
private:
    bool movingForward, movingBackward;
    unsigned int lifePoints;
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