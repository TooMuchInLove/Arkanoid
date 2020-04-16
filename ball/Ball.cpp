#include "Ball.h"

Ball::Ball(float x, float y, int radius, int speed, Vector3f color) : x(x), y(y), radius(radius), speed(speed), color(color) {

	direction.x = speed;
	direction.y = -speed;
	
	circ.setPosition(x, y);
	circ.setRadius(radius);
	circ.setFillColor(Color(color.x, color.y, color.z));
	circ.setOrigin(radius, radius);

}

void Ball::Move(int _winWidth, int _winHeight, bool &GAME_OVER) {

	circ.move(direction);	/* Начальное движение */
	
	if (circ.getPosition().x - radius < 0)				/* Если каснулся ЛЕВОЙ границы окна */
		direction.x = speed;
	
	else if (circ.getPosition().x + radius > _winWidth)	/* Если каснулся ПРАВОЙ границы окна */
		direction.x = -speed;
	
	if (circ.getPosition().y - radius < 0)				/* Если каснулся ВЕРХНЕЙ границы окна */
		direction.y = speed;
	
	else if (circ.getPosition().y + radius > _winHeight)/* Если каснулся НИЖНЕЙ границы окна */
		GAME_OVER = true;

}

void Ball::CollisionWithPlatform(vector <float> &param) {

	/* Взаимодействие шарика с платформой [ Верхняя грань ] */
	if (circ.getPosition().x >= param[1] && circ.getPosition().x <= param[1] + param[3]) {
		if (circ.getPosition().y + radius >= param[2]) {
			direction.y = -speed;
			return;
		}
	}
	
	if (circ.getPosition().y >= param[2] && circ.getPosition().y <= param[2] + param[4]) {
	
		/* Взаимодействие шарика с платформой [ Левая грань ] */
		if (circ.getPosition().x + radius >= param[1] && circ.getPosition().x + radius <= param[1] + param[3]) {
			direction.x = -speed;
			return;
		}
		
		/* Взаимодействие шарика с платформой [ Правая грань ] */
		if (circ.getPosition().x - radius <= param[1] + param[3] && circ.getPosition().x - radius >= param[1]) {
			direction.x = speed;
			return;
		}
	
	}

}

void Ball::CollisionWithDestructPlatform(float pos_x, float pos_y, int sw, int sh, int &count, bool &dest) {

	if ((pos_y <= circ.getPosition().y + radius) && (pos_y + sh >= circ.getPosition().y - radius) &&
		(pos_x <= circ.getPosition().x + radius) && (pos_x + sw >= circ.getPosition().x - radius) && !dest) {
	
		dest = true;	/* Фиксируем разрушение платформы */
		count--;		/* Кол-во разрушаемых платформ, которые остались */
		
		if (circ.getPosition().x >= pos_x && circ.getPosition().x <= pos_x + sw) {
		
			/* Взаимодействие шарика с платформой [ Верхняя грань ] */
			if (circ.getPosition().y - radius <= pos_y) {
				direction.y = -speed;
				return;
			}
			
			/* Взаимодействие шарика с платформой [ Нижняя грань ] */
			if (circ.getPosition().y + radius >= pos_y + sh) {
				direction.y = speed;
				return;
			}
		
		}
		
		if (circ.getPosition().y >= pos_y && circ.getPosition().y <= pos_y + sh) {
		
			/* Взаимодействие шарика с платформой [ Левая грань ] */
			if (circ.getPosition().x + radius >= pos_x && circ.getPosition().x + radius <= pos_x + sw) {
				direction.x = -speed;
				return;
			}
			
			/* Взаимодействие шарика с платформой [ Правая грань ] */
			else if (circ.getPosition().x - radius <= pos_x + sw && circ.getPosition().x - radius >= pos_x) {
				direction.x = speed;
				return;
			}
		
		}
	
	}

}

Ball::~Ball() {}
