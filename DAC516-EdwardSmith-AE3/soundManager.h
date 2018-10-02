#pragma once
#include "SDL_mixer.h"

class soundManager
{
public:
	
	~soundManager();

	static soundManager* Instance();
	Mix_Music* loadMusic(const char* pathway);
	void playMusic(Mix_Music* music);

	Mix_Chunk* loadSound(const char* pathway);
	void playSound(Mix_Chunk* sound);

private:
	soundManager();
	static soundManager* s_instance;
};

