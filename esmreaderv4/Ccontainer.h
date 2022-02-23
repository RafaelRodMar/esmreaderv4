#pragma once
#include "Entity.h"
class Ccontainer : public Entity
{
public:

	std::string m_text = "";
	std::list<Entity*> entities;

	Ccontainer() {
		m_name = "Ccontainer";
	}

	Ccontainer(Vector2D pos, int width, int height, std::string text);
	Ccontainer(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
		int row, int cframe, double Angle, int radius, std::string text, std::string font);
	~Ccontainer() {
		for (auto x : entities) delete(x);
		entities.clear();
	}

	void update();
	void draw();
	void handleEvents();

	void addEntity(Entity* e);
};

