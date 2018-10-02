#include "game.h"

#include "level.h"
#include "background.h"


SDL_Renderer* game::m_renderer = nullptr;
SDL_Event game::event;
bool game::isRunning;
SDL_RendererFlip game::flipType;

//std::vector<enemy*>Enemies;


level* Level;

background* Background;

game::game()
{
	

	m_window = nullptr;

	//Init
	SDL_Init(SDL_INIT_EVERYTHING);

	
	//Create window				
	m_window = SDL_CreateWindow(screenTitle, screenPosX, screenPosY, screenWidth, screenHeight, 0);

	if (!m_window)
	{
		std::cout << "Window init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue" << std::endl;
		getchar();
		return;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	if (!m_renderer)
	{
		std::cout << "Renderer init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue\n" << std::endl;
		getchar();
		return;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		std::cout << "Sound init failed: " << SDL_GetError() << std::endl;
		std::cout << "Press any key to continue\n" << std::endl;
		getchar();
		return;
	}

	isRunning = true;

	
	//Enemy = new enemy("Art/monster.bmp", NULL, NULL);
	//Enemy2 = new enemy("Art/monster.bmp", 10, screenHeight - entity::spriteHeight * 4);
	
	
	Level = new level("Levels/map0.txt", levelWidth, levelHeight, screenWidth, screenHeight);
	
	Background = new background();


	Mix_Music* music;
	music = soundManager::Instance()->loadMusic("Music/grief.mp3");
	soundManager::Instance()->playMusic(music);



	
	

	//Enemies.push_back(Enemy);
	//Enemies.push_back(Enemy2);

}


game::~game()
{
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
	}
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
	}
	if (Level)
	{
		delete Level;
		Level = nullptr;
	}
	if (Background)
	{
		delete Background;
		Background = nullptr;
	}
	
}

void game::setDisplayColour(int r, int g, int b, int a)
{
	if (m_renderer)
	{
		int result = SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	}
}


void game::render()
{
	
		SDL_RenderClear(m_renderer); //Wipes display to desired colour

		Background->render();
		
		Level->render();
		
		SDL_RenderPresent(m_renderer); //Presents colour						   //SDL_Delay(5000); //Delays for designated amount of time. in this case, 5 secs
}

void game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		

		break;
	default:
		break;
	}
}

void game::update()
{
	

	handleEvents();

	
	
/*	if (!Command)
	{
		Player->srcRect.x = 0;
	}*/
	
	Level->update();
		
	if (Level->checkLevel() == true)
	{

		goToNextLevel();
	}

	
	
	
}

void game::clean()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void game::goToNextLevel()
{
	
	++level_count;
	std::cout << level_count;
	std::string txt = ".txt";
	std::string levelPath = "Levels/map";
	std::string number = std::to_string(level_count);

	std::string levelnum = levelPath + number + txt;

	delete Level;
	Level = nullptr;
	

	Level = new level(levelnum, levelWidth, levelHeight, screenWidth, screenHeight);

	
}



