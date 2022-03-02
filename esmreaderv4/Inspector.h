#pragma once
#include "Entity.h"
#include "Hierarchy.h"
#include "Vector2D.h"

class Inspector : public Entity{
public:
	Hierarchy* hierarchy = nullptr;

	Inspector(Vector2D pos, int width, int height);

	void handleEvents();
	void update();
	void draw();
};

