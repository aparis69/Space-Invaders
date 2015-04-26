#include "SoundManager.h"

#include <iostream>
#include <exception>

using namespace std;

FMOD::System* SoundManager::system = nullptr;
FMOD::Sound* SoundManager::fireSounds[1];

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
    errCheck(system->init(2, FMOD_INIT_NORMAL, 0));
    loadRessources();
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
}

void SoundManager::fire(int i)
{
    errCheck(system->playSound(FMOD_CHANNEL_FREE, fireSounds[0], false, nullptr));
}

void SoundManager::fire(Missile* m)
{
    fire(0);
}
