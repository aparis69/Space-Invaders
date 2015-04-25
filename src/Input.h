#pragma once
#include "SDLinclude.h"

class Input
{
protected:
    bool key[SDLK_LAST];
    int mousex, mousey;
    int mousexrel, mouseyrel;
    char mousebuttons[8];
    bool quit;
public:
    // Constructor & Destructor
    Input();

    ~Input()
    {
    }

    // Poll events and updates structures.
    void Update();

    // Getter & Setter

    inline bool Key(int i)
    {
        return key[i];
    }

    inline int MouseX()
    {
        return mousex;
    }

    inline int MouseY()
    {
        return mousey;
    }

    inline int MouseXrel()
    {
        return mousexrel;
    }

    inline int MouseYrel()
    {
        return mouseyrel;
    }

    inline int MouseButton(int i)
    {
        return mousebuttons[i];
    }

    inline bool Quit()
    {
        return quit;
    }

    /** \brief Tells wether the player is pressing any direction arrow.
     *
     * \return bool True if player is moving
     *
     */
    bool isMoving() const;
};
