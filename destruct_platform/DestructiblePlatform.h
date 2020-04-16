#ifndef DESTRUCTIBLEPLATFORM_H
#define DESTRUCTIBLEPLATFORM_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class DestructiblePlatform {

	public:
		RectangleShape rect;	/* Платформа */
		Vector3f color;			/* Цвет платформы */
		int x;					/* Координаты платформы по x */
		int y;					/* Координаты платформы по y */
		int width;				/* Ширина платформы */
		int height;				/* Высота платформы */
		bool destroy;			/* Фиксируем разрушение платформ */
		
		DestructiblePlatform(int, int, int, int, Vector3f);
		
		~DestructiblePlatform();

};

#endif
