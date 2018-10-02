#include "game.h"



int main(int argc, char* argv[])
{
	game* Game = new game();

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	if (Game->returnRunning() == true)
	{
		int r = 255, g = 0, b = 0, a = 255;

		Game->setDisplayColour(r, g, b, a);

		while (Game->returnRunning() == true)
		{
			frameStart = SDL_GetTicks();

			
			Game->update();
			Game->render();
			frameTime = SDL_GetTicks() - frameStart;

			if (frameDelay > frameTime)
			{
				SDL_Delay(frameDelay - frameTime);
			}
		}

	}

	Game->clean(); //Destroys game renderer, window and calls SDL_Quit()
	delete Game;
	Game = nullptr;

	return 0;
}