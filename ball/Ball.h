#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Ball {

	public:
		CircleShape circ;	/* Шарик */
		Vector2f direction;	/* Направление движения шарика */
		Vector3f color;		/* Цвет шарика */
		float x;			/* Координаты шара по x */
		float y;			/* Координаты шара по y */
		int radius;			/* Радиус шара */
		int speed;			/* Скорость шара */
		
		Ball(float, float, int, int, Vector3f);
		
		~Ball();
		
		void Move(int, int, bool &);
		
		void CollisionWithPlatform(vector <float> &param_p);
		
		void CollisionWithDestructPlatform(float, float, int, int, int &, bool &);

};

#endif
