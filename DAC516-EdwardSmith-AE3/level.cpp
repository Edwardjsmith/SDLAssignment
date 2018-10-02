#include "level.h"



level::level(std::string fileName, int sizeX, int sizeY, int screenW, int screenH)
{
	screenWidth = screenW;
	screenHeight = screenH;

	camera = { 0, 0, screenW, screenH };

	m_src.x = m_src.y = 0;
	m_src.w = m_src.h = 32;
	m_dest.w = m_dest.h = 32;
	m_dest.x = m_dest.y = 0;

	Input = new input();

	char tile;
	std::fstream mapFile;

	mapFile.open(fileName);
	

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile >> tile;
			//mapFile.ignore();
			m_dest.x = x*(m_dest.w);
			m_dest.y = y*(m_dest.h);


			//std::cout << tile << std::endl;
			switch (tile)
			{

			case '0': break;


			case '1':
				obj.push_back(new gameObject("Art/black.bmp", m_dest.x, m_dest.y));
				break;

			case '2':
				finishLine = new gameObject("Art/finish.bmp", m_dest.x, m_dest.y);
				
				break;

			case '3':
				Player = new player("Art/player.bmp", m_dest.x, m_dest.y);
				break;

			case '4':
				Enemy.push_back(new enemy("Art/Goblin.bmp", m_dest.x, m_dest.y));
				break;

			case '5':
					pickMeUp = new gameObject("Art/theKey.bmp", m_dest.x, m_dest.y);
					break;


			default: break;
			}
		}
	}
	mapFile.close();
}

/*Function that renders all level objects*/
void level::render()
{
	
	for (size_t i = 0; i < obj.size(); i++)
	{
		if (obj[i] != nullptr)
		{
			obj[i]->render(camera.x, camera.y, SDL_FLIP_NONE);
		}
	}
	for (size_t i = 0; i < Enemy.size(); i++)
	{
		if (Enemy[i]->isActive == true && Enemy[i] != nullptr)
		{
			Enemy[i]->render(camera.x, camera.y, SDL_FLIP_NONE);
			
		}	
	}

	if (finishLine->isActive == true && finishLine != nullptr)
	{
		finishLine->render(camera.x, camera.y, SDL_FLIP_NONE);
	}
	if (pickMeUp->isActive == true && pickMeUp != nullptr)
	{
		pickMeUp->render(camera.x, camera.y, SDL_FLIP_NONE);
	}

	if (Player->isActive == true)
	{
		Player->render(camera.x, camera.y, SDL_FLIP_NONE);
	}
}


void level::update()
{

	Command = Input->updateInput();

	if (Command)
	{
		Command->execute(*Player);
	}

	if (finishLine != nullptr)
	{
		if (Collision.collidesTop(*finishLine, *Player) && collectableCount == true || Collision.collidesBottomFull(*finishLine, *Player) && collectableCount == true)
		{
			collectableCount = false;
			finishLine->setActive(false);
			nextLevel = true;
		}
	}

	if (pickMeUp != nullptr)
	{
		if (Collision.collidesTop(*pickMeUp, *Player) || Collision.collidesBottomFull(*pickMeUp, *Player))
		{
			pickMeUp->setActive(false);
			collectableCount = true;
		}
	}


	//Enemy[0]->jump();

	for (size_t j = 0; j < Enemy.size(); j++)
	{
		for (size_t i = 0; i < obj.size(); i++)
		{


			if (Collision.collidesBottomFull(*Player, *obj[i]))
			{

				Player->setCollided(true);

			}
			if (Collision.collidesBottomFull(*Enemy[j], *obj[i]))
			{
				Enemy[j]->setCollided(true);
			}
			if (Collision.collidesBottomFull(*Player, *Enemy[j]))
			{
				Enemy[j]->setActive(false);

			}
			if (Collision.collidesTop(*Player, *Enemy[j]))
			{
				//collide = true;
				Player->setActive(false);
				//play->setCollided(true);
				game::updateRunning(false);
			}
			if (Collision.collidesTop(*Enemy[j], *obj[i]))
			{
				monsterSpeed *= -1;
			}

			Collision.collidesTop(*Player, *obj[i]);
			
		}
		}
	Enemy[0]->setX(monsterSpeed);
	Enemy[0]->update();
		
		Player->update();
		collide = false;

		camera.x = (Player->getX() + entity::spriteWidth / 2) - screenWidth / 2;  //Ensures the camera follows the player in the x
		camera.y = (Player->getY() + entity::spriteHeight / 2) - screenHeight / 2; //Does the same for y
	}





level::~level()
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		if (obj[i])
		{
			delete obj[i];
			obj[i] = nullptr;
		}
	}
	for (size_t i = 0; i < Enemy.size(); i++)
	{
		if (Enemy[i])
		{
			delete Enemy[i];
			Enemy[i] = nullptr;
		}
	}

	if (finishLine)
	{
		delete finishLine;
		finishLine = nullptr;
	}
	if (pickMeUp)
	{
		delete pickMeUp;
		pickMeUp = nullptr;
	}
	if (Player)
	{
		delete Player;
		Player = nullptr;
	}
}
