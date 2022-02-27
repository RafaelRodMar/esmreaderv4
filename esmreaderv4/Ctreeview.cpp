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
		InputHandler::Instance()->setMouseWheelToFalse();

		if (Game::Instance()->mouseClicked)
		{
			int y = v->m_y / 20 - 1;
			selected = index + y;
			if (selected > data.size()) selected = data.size() - 1;
		}
	}
}

void Ctreeview::update() {

}

void Ctreeview::draw() {
	int ypos = m_position.m_y;
	for (int i = index; i < data.size(); i++) {
		SDL_Color cl = SDL_Color({ 255,255,255,0 });
		if (i == selected) cl = SDL_Color({ 128,128,128,0 });
		AssetsManager::Instance()->Text(data[i].text, "font", m_position.m_x, ypos, cl, Game::Instance()->getRenderer());
		/*if (i == selected && data[i].showElements)
		{
			for (auto x : data[i].elements) {
				AssetsManager::Instance()->Text(x, "font", m_position.m_x + 20, ypos, cl, Game::Instance()->getRenderer());
				ypos += 20;
			}
		}*/
		ypos += 20;
	}
}

Ctreeview::~Ctreeview()
{
}
