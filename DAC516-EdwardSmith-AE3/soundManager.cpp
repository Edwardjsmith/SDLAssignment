#include "soundManager.h"

soundManager* soundManager::s_instance = nullptr;

soundManager::soundManager()
{
}


soundManager::~soundManager()
{
}

soundManager * soundManager::Instance()
{
	if (s_instance == nullptr)
	{
		s_instance = new soundManager();

		return s_instance;
	}

	return s_instance;
}

Mix_Music* soundManager::loadMusic(const char* pathway)
{
	
		
		Mix_Music* music;
		music = Mix_LoadMUS(pathway);

		return music;
}

void soundManager::playMusic(Mix_Music* music)
{
	
	Mix_PlayMusic(music, -1);
	
/*	if (isMusic == false)
	{
		Mix_Chunk* sound = dynamic_cast<Mix_Chunk*>(sound);

		Mix_PlayChannel(-1, sound, 1);
	}*/
}

Mix_Chunk * soundManager::loadSound(const char * pathway)
{
	Mix_Chunk* sound;
	sound = Mix_LoadWAV(pathway);
	return sound;
}

void soundManager::playSound(Mix_Chunk * sound)
{
	Mix_PlayChannel(-1, sound, 0);
}
