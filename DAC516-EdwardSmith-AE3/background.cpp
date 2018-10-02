#include "background.h"

int lvl[lvlSizeX][lvlSizeY]
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0 },
	{ 0,0,3,3,3,0,0,0,0,0,0,0,1,1,2,1,2,1,1,0 },
	{ 0,3,3,3,3,3,0,0,0,0,1,1,1,1,1,1,1,1,1,1 },
	{ 0,0,3,3,3,0,0,0,0,0,0,0,1,2,1,1,1,2,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
	{ 0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },


};



background::background()
{
	sky = textureManager::load("Art/sky.bmp");
	sun = textureManager::load("Art/sun.bmp");
	black = textureManager::load("Art/black.bmp");
	cloud = textureManager::load("Art/cloud.bmp");

	loadMap(lvl);

	m_src.x = m_src.y = 0;
	m_src.w = m_src.h = 32;
	m_dest.w = m_dest.h = 32;
	m_dest.x = m_dest.y = 0;
}

void background::render()
{
	int type = 0;

	for (int y = 0; y < lvlSizeY; y++)
	{
		for (int x = 0; x < lvlSizeX; x++)
		{

			type = m_level[y][x];

			m_dest.x = x * 32;
			m_dest.y = y * 32;

			switch (type)
			{
			case 0:

				textureManager::draw(sky, m_src, m_dest);
				break;

			case 1:

				textureManager::draw(sun, m_src, m_dest);
				break;

			case 2:

				textureManager::draw(black, m_src, m_dest);
				break;

			case 3:

				textureManager::draw(cloud, m_src, m_dest);
				break;

			default: break;

			}
		}
	}
}




background::~background()
{
}

void background::loadMap(int arr[lvlSizeX][lvlSizeY])
{
	for (int y = 0; y < lvlSizeY; y++)
	{
		for (int x = 0; x < lvlSizeX; x++)
		{

			m_level[y][x] = arr[y][x];

			
		}
	}

}

