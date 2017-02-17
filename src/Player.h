#pragma once
#include "GameObject.h"
#include "Params.h"

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
    Player();
    Player(int speed);

    ~Player();

	void resetLifePoints();
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