#pragma once
class vector2D
{
public:
	int m_x;
	int m_y;

	vector2D()
	{
		m_x = 1;
		m_y = 1;
	}

	int velocity(int x, int y, int speed)
	{
		return x += m_x * speed, y += m_y * speed;

		
	}


	~vector2D();



};

