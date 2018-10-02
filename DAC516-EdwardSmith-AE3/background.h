#include <string>
#include "textureManager.h"
#include <vector>
#include <fstream>

const int lvlSizeX = 20;
const int lvlSizeY = 20;

class background
{

public:
	//Initializes position and type
	background();
	~background();



	//Shows the tile
	void render();
	int m_level[lvlSizeX][lvlSizeY];

	void loadMap(int arr[lvlSizeX][lvlSizeY]);


private:
	//The attributes of the tile
	SDL_Rect m_src, m_dest;

	SDL_Texture* sky;
	SDL_Texture* sun;
	SDL_Texture* black;
	SDL_Texture* cloud;

	//The tile type
	int mType;
	

	

	

};