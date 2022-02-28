#pragma once
#include "Entity.h"
#include "Vector2D.h"
#include "Ctreeview.h"

class Hierarchy : public Entity{
public:
	Ctreeview* ctree = nullptr;

	Hierarchy(Vector2D pos, int width, int height);
	~Hierarchy();

	void handleEvents();
	void update();
	void draw();
};