#pragma once
#include "Entity.h"

class Clabel : public Entity {
public:

	std::string m_text = "";

	Clabel() {
		m_name = "Clabel";
	}

	void ClabelSettings(Vector2D pos, int width, int height, std::string text);
	void ClabelSettings(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
		int row, int cframe, double Angle, int radius, std::string text, std::string font);

	void update();
	void draw();
	void handleEvents();
};