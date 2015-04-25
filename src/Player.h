#pragma once
#include "GameObject.h"

class Player : public GameObject
{
private:
    bool movingForward, movingBackward;
public:
    // Constructor & Destructor
    Player(void);
    Player(float speed);

    ~Player(void)
    {
    }

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
};

