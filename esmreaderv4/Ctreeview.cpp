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

}

void Ctreeview::update() {

}

void Ctreeview::draw() {
	//CHANGE THIS. Create a texture in the constructor and store it until label destruction.
	AssetsManager::Instance()->Text("treeview", "font", m_position.m_x, m_position.m_y, SDL_Color({ 255,255,255,0 }), Game::Instance()->getRenderer());
}

Ctreeview::~Ctreeview()
{
}
