#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>
#include <map>

class Missile;

class SoundManager
{
public:
    static void init();
    static void quit();

    static void fire(Missile*);
private:
    SoundManager(){;}
    static void errCheck(FMOD_RESULT result);
    static void loadRessources();

    static FMOD::System *system;
    static FMOD::Sound *fireSounds[1];

    static void fire(int);
};

#endif // SOUNDMANAGER_H
