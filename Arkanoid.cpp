#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <unistd.h>

#include "destruct_platform/DestructiblePlatform.h"
#include "platform/Platform.h"
#include "ball/Ball.h"
#include "level/level.h"

using namespace std;
using namespace sf;

const int winWidth = 1000;	/* ������ ���� */
const int winHeight = 700;	/* ������ ���� */
const int width = 118;		/* ������ ����������� ��������� */
const int height = 20;		/* ������ ����� ��������� */

int main() {

	vector <DestructiblePlatform*> destruct;	/* ����������� ��������� */
	
	Platform* platform = new Platform( (winWidth - width) / 2, winHeight - 30, 150, height, 5, Vector3f(52, 73, 94) );	/* ������� ��������� */
	
	Ball* ball = new Ball( winWidth / 2, winHeight - 40, 10, 5, Vector3f(255, 255, 255) );	/* ����� */
	
	RenderWindow window( VideoMode( winWidth, winHeight ), "Arkanoid | Press <Space> to start the game." );	/* ������� ���� ���������� */
	
	window.setFramerateLimit(100);	/* ������� ������ */
	
	y = 9;
	for (int j = 1; j < MaxHeiPD + 1; j++) {
		x = 5;
		for (int i = 1; i < MaxLenPD + 1; i++) {
			if (MAP_1[j][i] == '#')	/* ���� �������� ��������� ���� � ������� */
				destruct.push_back(new DestructiblePlatform( x, y, width, height, Vector3f(x + y, i, j) ));
			x += width + 5;
		}
		y += height + 5;
	}
	
	count_dest_dp = destruct.size();			/* ���-�� ����������� �������� */
	
	while (window.isOpen()) {
	
		window.clear(Color(23, 32, 42));		/* ���� ���� */
		
		Event event;
		while (window.pollEvent(event)) {
		
			if (event.type == Event::Closed)	/* �������� ���� �� ������ */
				window.close();
			
			/* ���� ����� ������, �� ���� ����������� */
			if (Keyboard::isKeyPressed(Keyboard::Space))
				START_GAME = true;
		
		}
		
		if (START_GAME) {
			
			platform->Move(winWidth);						/* �������� ��������� */
			vector <float> p1(platform->GetPosition());		/* ���������� ��������� ��������� */
			window.draw(platform->rect);					/* ��������� ��������� */
			
			ball->Move(winWidth, winHeight, END_GAME);		/* �������� ������ */
			ball->CollisionWithPlatform(p1);				/* �������������� ������ � ���������� */
			window.draw(ball->circ);						/* ��������� ������ */
			
			for (int i = 0; i < destruct.size(); i++) {		/* ��������� ����������� �������� */
				if (!destruct[i]->destroy)
					window.draw(destruct[i]->rect);
			}
			
			for (int i = 0; i < destruct.size(); i++) {		/* ���������� ��������� ������ �� ����������� ��������� */
				float pos_x = destruct[i]->rect.getPosition().x;
				float pos_y = destruct[i]->rect.getPosition().y;
				ball->CollisionWithDestructPlatform(pos_x, pos_y, width, height, count_dest_dp, destruct[i]->destroy);
			}
			
			if (count_dest_dp == 0) {	/* �� ������ ������ */
				window.setTitle("Arkanoid | You Won! | Closing in 3 seconds...");
				sleep(3);
				window.close();
			}
			
			if (END_GAME) {	/* �� ������ ��������� */
				window.setTitle("Arkanoid | You Lose! | Closing in 3 seconds...");
				sleep(3);
				window.close();
			}
		
		}
		
		window.display();
	
	}
	
	return 0;

}
