#include "Platform.h"

Platform::Platform(float x, float y, int width, int height, int speed, Vector3f color) : x(x), y(y), width(width), height(height), speed(speed), color(color) {

	rect.setPosition(x, y);
	rect.setSize(Vector2f(width, height));
	rect.setFillColor(Color(color.x, color.y, color.z));

}

void Platform::Move(int _windowWidth) {

	if(Keyboard::isKeyPressed(Keyboard::Right)) {
		if (rect.getPosition().x <= _windowWidth - width)
			rect.move( speed, 0.0 );
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		if (rect.getPosition().x >= 0)
			rect.move( -speed, 0.0 );
	}

}

vector <float> Platform::GetPosition() {

	vector <float> param(4);
	
	param[1] = rect.getPosition().x;	/* Положение платформы по x */
	param[2] = rect.getPosition().y;	/* Положение платформы по y */
	param[3] = width;					/* Ширина платформы */
	param[4] = height;					/* Высота платформы */
	
	return param;

}

Platform::~Platform() {}
