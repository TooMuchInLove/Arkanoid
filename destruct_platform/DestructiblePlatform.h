#ifndef DESTRUCTIBLEPLATFORM_H
#define DESTRUCTIBLEPLATFORM_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class DestructiblePlatform {

	public:
		RectangleShape rect;	/* ��������� */
		Vector3f color;			/* ���� ��������� */
		int x;					/* ���������� ��������� �� x */
		int y;					/* ���������� ��������� �� y */
		int width;				/* ������ ��������� */
		int height;				/* ������ ��������� */
		bool destroy;			/* ��������� ���������� �������� */
		
		DestructiblePlatform(int, int, int, int, Vector3f);
		
		~DestructiblePlatform();

};

#endif
