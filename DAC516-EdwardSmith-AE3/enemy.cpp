#include "enemy.h"



enemy::enemy(const char* filename, int x, int y) : entity::entity(filename, x, y)
{
}


enemy::~enemy()
{
}

/*void enemy::render(int camX, int camY)
{
	SDL_Rect draw{ m_xpos -= camX, m_ypos -= camY, destRect.w, destRect.h };

	SDL_RenderCopy(game::m_renderer, m_entityTexture, NULL, &draw);
}*/
