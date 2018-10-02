#pragma once
#include "SDL.h"
#include <vector>
#include <stdio.h>
#include <iostream>

#ifndef GAME_H
#define GAME_H

class game
{
public:
	game();
	~game();




	//The dimensions of the level
	const int levelWidth = 30;
	const int levelHeight = 30;

	//Screen dimension constants
	const int screenWidth = 640;
	const int screenHeight = 480;

	//Screen position constants
	const int screenPosX = 50;
	const int screenPosY = 50;

	//Window title
	const char* screenTitle = "DAC516-ESmith-AE3";


	void setDisplayColour(int r, int g, int b, int a);

	static SDL_Renderer* m_renderer; //Render is set as a public static to allow it to be called across the program. Means a new instance doesn't have to be made in
									 //another class 
	static SDL_RendererFlip flipType;

	void render();

	void handleEvents();

	void update();
	void clean();



	static SDL_Event event;

	
	static bool updateRunning(bool run)
	{
		return isRunning = run;
	}

	static bool returnRunning()
	{
		return isRunning;
	}
	
private:

	static bool isRunning;
	SDL_Window* m_window;
	

	void goToNextLevel();
	int level_count = 0;
		

	

};
#endif
