#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Ball {

	public:
		CircleShape circ;	/* ����� */
		Vector2f direction;	/* ����������� �������� ������ */
		Vector3f color;		/* ���� ������ */
		float x;			/* ���������� ���� �� x */
		float y;			/* ���������� ���� �� y */
		int radius;			/* ������ ���� */
		int speed;			/* �������� ���� */
		
		Ball(float, float, int, int, Vector3f);
		
		~Ball();
		
		void Move(int, int, bool &);
		
		void CollisionWithPlatform(vector <float> &param_p);
		
		void CollisionWithDestructPlatform(float, float, int, int, int &, bool &);

};

#endif
