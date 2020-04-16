#ifndef PLATFORM_H
#define PLATFORM_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Platform {

	public:
		RectangleShape rect;	/* ��������� */
		Vector3f color;			/* ���� ��������� */
		float x;				/* ���������� ��������� �� x */
		float y;				/* ���������� ��������� �� y */
		int width;				/* ������ ��������� */
		int height;				/* ������ ��������� */
		int speed;				/* �������� ��������� */
		
		Platform(float, float, int, int, int, Vector3f);
		
		~Platform();
		
		void Move(int);
		
		vector <float> GetPosition();

};

#endif
