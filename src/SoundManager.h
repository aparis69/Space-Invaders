#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <fmodex/fmod.hpp>
#include <fmodex/fmod_errors.h>
#include <map>
#include <SDL/SDL.h>

class Missile;
class Input;

class SoundManager
{
public:
    static void init();
    static void quit();

    static void fire(Missile*);
    static void update(Input& in);
private:
    SoundManager(){;}
    static Uint32 lastInputUpdate;
    static void errCheck(FMOD_RESULT result);
    static void loadRessources();

    static FMOD::System *system;
    static FMOD::Sound *fireSounds[1];
    static FMOD::Sound* musics[1];
    static FMOD::Channel* musicChannel;

    static void fire(int);

    static void startMusic();
    static void stopMusic();
    static void toggleMusic();
};

#endif // SOUNDMANAGER_H
