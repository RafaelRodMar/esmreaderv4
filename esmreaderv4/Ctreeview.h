#pragma once
#include "Entity.h"

class Ctreeview : public Entity {
public:
	Ctreeview() {
		m_name = "Ctreeview";
	}
	~Ctreeview();

	Ctreeview(Vector2D pos, int width, int height);
	Ctreeview(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
		int row, int cframe, double Angle, int radius, std::string text, std::string font);

	void update();
	void draw();
	void handleEvents();
};

