#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Platform {

	public:
		RectangleShape rect;	/* ѕлатформа */
		Vector3f color;			/* ÷вет платформы */
		float x;				/* координаты платформы по x */
		float y;				/* координаты платформы по y */
		int width;				/* ширина платформы */
		int height;				/* высота платформы */
		int speed;				/* скорость платформы */
		
		Platform(float, float, int, int, int, Vector3f);
		
		~Platform();
		
		void Move(int);
		
		vector <float> GetPosition();

};

#endif
