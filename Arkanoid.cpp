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

const int winWidth = 1000;	/* Ширина ОКНА */
const int winHeight = 700;	/* Высота ОКНА */
const int width = 118;		/* Ширина разрушаемой платформы */
const int height = 20;		/* Высота любой платформы */

int main() {

	vector <DestructiblePlatform*> destruct;	/* РАЗРУШАЕМЫЕ ПЛАТФОРМЫ */
	
	Platform* platform = new Platform( (winWidth - width) / 2, winHeight - 30, 150, height, 5, Vector3f(52, 73, 94) );	/* ГЛАВНАЯ ПЛАТФОРМА */
	
	Ball* ball = new Ball( winWidth / 2, winHeight - 40, 10, 5, Vector3f(255, 255, 255) );	/* ШАРИК */
	
	RenderWindow window( VideoMode( winWidth, winHeight ), "Arkanoid | Press <Space> to start the game." );	/* СОЗДАЁМ ОКНО ПРИЛОЖЕНИЯ */
	
	window.setFramerateLimit(100);	/* ЧАСТОТА КАДРОВ */
	
	y = 9;
	for (int j = 1; j < MaxHeiPD + 1; j++) {
		x = 5;
		for (int i = 1; i < MaxLenPD + 1; i++) {
			if (MAP_1[j][i] == '#')	/* Если условная платформа есть в массиве */
				destruct.push_back(new DestructiblePlatform( x, y, width, height, Vector3f(x + y, i, j) ));
			x += width + 5;
		}
		y += height + 5;
	}
	
	count_dest_dp = destruct.size();			/* Кол-во разрушенных платформ */
	
	while (window.isOpen()) {
	
		window.clear(Color(23, 32, 42));		/* Цвет фона */
		
		Event event;
		while (window.pollEvent(event)) {
		
			if (event.type == Event::Closed)	/* Закрытие ОКНА на кнопку */
				window.close();
			
			/* Если нажат ПРОБЕЛ, то игра запускается */
			if (Keyboard::isKeyPressed(Keyboard::Space))
				START_GAME = true;
		
		}
		
		if (START_GAME) {
			
			platform->Move(winWidth);						/* Движение платформы */
			vector <float> p1(platform->GetPosition());		/* Возвращаем положение платформы */
			window.draw(platform->rect);					/* Отрисовка платформы */
			
			ball->Move(winWidth, winHeight, END_GAME);		/* Движение шарика */
			ball->CollisionWithPlatform(p1);				/* Взаимодействие шарика с платформой */
			window.draw(ball->circ);						/* Отрисовка шарика */
			
			for (int i = 0; i < destruct.size(); i++) {		/* Отрисовка разрушаемых платформ */
				if (!destruct[i]->destroy)
					window.draw(destruct[i]->rect);
			}
			
			for (int i = 0; i < destruct.size(); i++) {		/* Определяем попадание шарика по разрушаемой платформе */
				float pos_x = destruct[i]->rect.getPosition().x;
				float pos_y = destruct[i]->rect.getPosition().y;
				ball->CollisionWithDestructPlatform(pos_x, pos_y, width, height, count_dest_dp, destruct[i]->destroy);
			}
			
			if (count_dest_dp == 0) {	/* На случай ПОБЕДЫ */
				window.setTitle("Arkanoid | You Won! | Closing in 3 seconds...");
				sleep(3);
				window.close();
			}
			
			if (END_GAME) {	/* На случай ПОРАЖЕНИЯ */
				window.setTitle("Arkanoid | You Lose! | Closing in 3 seconds...");
				sleep(3);
				window.close();
			}
		
		}
		
		window.display();
	
	}
	
	return 0;

}
