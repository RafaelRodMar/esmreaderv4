#pragma once
#include "Entity.h"
#include "Vector2D.h"

class Inspector : public Entity{
public:

	Inspector(Vector2D pos, int width, int height) {}

	void handleEvents();
	void update();
	void draw();
};

