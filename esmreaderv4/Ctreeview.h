#pragma once
#include "Entity.h"

struct CellNode {
	int cell = -1;
	int element = -1;
	std::string text;
	bool show = true;
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

