#pragma once
#include "Entity.h"

struct CellNode {
	int type = 0; //0 = cell, 1 = element of cell
	int cellIndex = 0;
	std::string text;
	bool showElements = false;
	std::vector<std::string> elements;
};

class Ctreeview : public Entity {
public:
	Ctreeview() {
		m_name = "Ctreeview";
	}
	~Ctreeview();

	std::vector<CellNode> data;
	int index = 0;
	int selected = -1;

	Ctreeview(Vector2D pos, int width, int height);
	Ctreeview(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
		int row, int cframe, double Angle, int radius, std::string text, std::string font);

	void setData(std::vector<CellNode> &temp) {
		data = temp;
	}

	void update();
	void draw();
	void handleEvents();
};

