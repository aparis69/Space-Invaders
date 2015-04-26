#include "SoundManager.h"
#include "Input.h"
#include "Enemy.h"

#include <iostream>
#include <exception>

using namespace std;

FMOD::System* SoundManager::system = nullptr;
FMOD::Sound* SoundManager::fireSounds[1];
FMOD::Sound* SoundManager::musics[1];
FMOD::Sound* SoundManager::playerCollisions[1];
FMOD::Channel* SoundManager::musicChannel;
Uint32 SoundManager::lastInputUpdate;

void SoundManager::errCheck(FMOD_RESULT result)
{
    if (result != FMOD_OK)
    {
        cout << "FMOD error n" << result << ": " << FMOD_ErrorString(result) << endl;
        throw exception();
    }
}

void SoundManager::init()
{
    errCheck(FMOD::System_Create(&system));
    errCheck(system->init(10, FMOD_INIT_NORMAL, 0));
    loadRessources();
    lastInputUpdate = -1;
}

void SoundManager::quit()
{
    for(FMOD::Sound* s : fireSounds)
        s->release();
    errCheck(system->close());
    errCheck(system->release());
}

void SoundManager::loadRessources()
{
    errCheck(system->createSound("Audio/FireNormal.wav", FMOD_CREATESAMPLE, 0, &fireSounds[0]));
    errCheck(system->createSound("Audio/Music/Teleporter.mp3", FMOD_CREATESTREAM | FMOD_SOFTWARE | FMOD_2D | FMOD_LOOP_NORMAL,
                                 0, &musics[0]));
    musics[0]->setLoopCount(-1);
    errCheck(system->createSound("Audio/Collisions/Player/Enemy1.wav", FMOD_CREATESAMPLE, 0, &playerCollisions[0]));

    errCheck(system->playSound(FMOD_CHANNEL_FREE, musics[0], true, &musicChannel));

}

void SoundManager::fire(int i)
{
    errCheck(system->playSound(FMOD_CHANNEL_FREE, fireSounds[0], false, nullptr));
}

void SoundManager::fire(Missile* m)
{
    fire(0);
}

void SoundManager::startMusic()
{
    errCheck(musicChannel->setPaused(false));
}

void SoundManager::stopMusic()
{
    errCheck(musicChannel->setPaused(true));
}

void SoundManager::toggleMusic()
{
    bool paused;
    musicChannel->getPaused(&paused);
    musicChannel->setPaused(!paused);
}

void SoundManager::update(Input& in)
{
    Uint32 now = SDL_GetTicks();
    if(now - lastInputUpdate > 50)
    {
        lastInputUpdate = now;
        if(in.Key(SDLK_m))
        {
            toggleMusic();
        }
    }
}

void SoundManager::playerCollide(int i)
{
    errCheck(system->playSound(FMOD_CHANNEL_FREE, playerCollisions[0], false, nullptr));
}

void SoundManager::playerCollide(ObjectTypes o)
{
    int ind;
    switch(o)
    {
        case ObjectTypes::Enemy:
            ind = 0;
            break;
        default:
            ind = -1;
    }
    if(ind >= 0)
        playerCollide(ind);
}
