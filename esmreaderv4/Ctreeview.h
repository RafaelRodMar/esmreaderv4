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

	struct TreeViewData {
		std::string text;
		bool show = false;
		std::vector<std::string> elements;
	};
	std::vector < TreeViewData > tvdata;

	std::vector<CellNode> data;
	int index = 0;
	int selected = -1;
	int cellSelected = -1;

	Ctreeview(Vector2D pos, int width, int height);
	Ctreeview(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
		int row, int cframe, double Angle, int radius, std::string text, std::string font);

	void addData(std::string str, std::vector<std::string> vstr) {
		TreeViewData tvd;
		tvd.text = str;
		tvd.show = false;
		tvd.elements = vstr;
		tvdata.push_back(tvd);
	}

	void setData() {
		data.clear();
		for (int i = 0; i < tvdata.size();i++) {
			CellNode cn;
			cn.cell = i;
			cn.element = -1;
			cn.show = tvdata[i].show;
			cn.text = tvdata[i].text;
			data.push_back(cn);
			if (cellSelected == i)
			{
				selected = i;
				if (tvdata[i].elements.size() > 0)
				{
					for (int j = 0; j < tvdata[i].elements.size(); j++) {
						CellNode cne;
						cne.cell = i;
						cne.element = j;
						cne.show = true;
						cne.text = tvdata[i].elements[j];
						data.push_back(cne);
					}
				}
			}
		}
	}

	void update();
	void draw();
	void handleEvents();
};

