#include "Clabel.h"
#include "game.h"

void Clabel::handleEvents() {
}

void Clabel::update()
{
}

void Clabel::draw()
{
	//CHANGE THIS. Create a texture in the constructor and store it until label destruction.
	AssetsManager::Instance()->Text(m_text, "font", m_position.m_x, m_position.m_y, SDL_Color({ 0,0,0,0 }), Game::Instance()->getRenderer());
}

void Clabel::ClabelSettings(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
	int row, int cframe, double Angle, int radius, std::string text, std::string font) {
	m_text = text;
	settings(Texture, pos, vel, Width, Height, nFrames, row, cframe, Angle, radius);
}

void Clabel::ClabelSettings(Vector2D pos, int width, int height, std::string text) {
	m_text = text;
	settings("", pos, Vector2D(0, 0), width, height, 0, 0, 0, 0.0, 0);
}
