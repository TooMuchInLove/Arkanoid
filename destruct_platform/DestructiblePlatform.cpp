#include "DestructiblePlatform.h"

DestructiblePlatform::DestructiblePlatform(int x, int y, int width, int height, Vector3f color) : x(x), y(y), width(width), height(height), color(color) {

	destroy = false;
	
	rect.setPosition(x, y);
	rect.setSize(Vector2f(width, height));
	rect.setFillColor(Color(color.x, color.y, color.z));

}

DestructiblePlatform::~DestructiblePlatform() {}
