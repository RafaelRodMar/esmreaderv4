#include "Ctreeview.h"
#include "game.h"

Ctreeview::Ctreeview(Vector2D pos, int width, int height) :
	Entity("", pos, Vector2D(0, 0), width, height, 0, 0, 0, 0.0, 0) {
	m_name = "Ctreeview";
}

Ctreeview::Ctreeview(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
	int row, int cframe, double Angle, int radius, std::string text, std::string font) :
	Entity(Texture, pos, vel, Width, Height, nFrames, row, cframe, Angle, radius) {
	m_name = "Ctreeview";
}

void Ctreeview::handleEvents() {
	Vector2D* v = InputHandler::Instance()->getMousePosition();
	if (v->m_x > m_position.m_x && v->m_x < m_position.m_x + m_width &&
		v->m_y > m_position.m_y && v->m_y < m_position.m_y + m_height)
	{
		//mouse wheel
		if (InputHandler::Instance()->isMouseWheelUp())
		{
			if (index > 0) index -= 10;
		}
		if (InputHandler::Instance()->isMouseWheelDown())
		{
			if (index < data.size()) index += 10;
		}
		if (index < 0) index = 0;
		if (index >= data.size()) index = data.size() - 1;
		InputHandler::Instance()->setMouseWheelToFalse();

		if (Game::Instance()->mouseClicked)
		{
			offset = v->m_y / 20 - 1;
			int newSelected = index + offset;
			if (newSelected >= data.size()) newSelected = data.size() - 1;
			if (newSelected != selected)
			{
				//if it is a cell then reload new data
				if (data[newSelected].element == -1)
				{
					cellSelected = data[newSelected].cell;
					setData();
				}
				else
				{
					selected = newSelected;
				}
			}
		}
	}
}

void Ctreeview::update() {

}

void Ctreeview::draw() {
	int ypos = m_position.m_y;
	for (int i = index; i < data.size(); i++) {
		int xpos = m_position.m_x;
		SDL_Color cl = SDL_Color({ 255,255,255,0 });
		if (i == selected) cl = SDL_Color({ 128,128,128,0 });
		if (data[i].element != -1) xpos += 50;
		AssetsManager::Instance()->Text(data[i].text, "font", xpos, ypos, cl, Game::Instance()->getRenderer());
		ypos += 20;
		if (ypos > m_position.m_y + m_height) break;
	}
}

Ctreeview::~Ctreeview()
{
}
