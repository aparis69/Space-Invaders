#pragma once
#include "SDLinclude.h"

#include <vector>
class Input
{
protected:
    bool key[SDLK_LAST];
    std::vector<SDLKey> uppedKeys;
    int mousex, mousey;
    int mousexrel, mouseyrel;
    char mousebuttons[8];
    bool quit;
public:
    // Constructor & Destructor
    Input();

    ~Input();

    // Poll events and updates structures.
    void Update();

    // Getter & Setter
    bool Key(int i) const;

    int MouseX() const;

    int MouseY() const;

    int MouseXrel() const;

    int MouseYrel() const;

    int MouseButton(int i) const;

    bool Quit() const;

    /** \brief Tells wether the player is pressing any direction arrow.
     *
     * \return bool True if player is moving
     *
     */
    bool isMoving() const;

    bool wasKeyUpped(SDLKey) const;
};
