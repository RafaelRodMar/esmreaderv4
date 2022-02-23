#include "Ccontainer.h"
#include "game.h"

void Ccontainer::handleEvents() {
	for (auto i : entities)
		i->handleEvents();
}

void Ccontainer::update()
{
	for (auto i : entities)
		i->update();
}

void Ccontainer::draw()
{
	for (auto i : entities)
		i->draw();
}

Ccontainer::Ccontainer(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames,
	int row, int cframe, double Angle, int radius, std::string text, std::string font) : 
	Entity(Texture, pos, vel, Width, Height, nFrames, row, cframe, Angle, radius) {
	m_name = "Ccontainer";
	m_text = text;
}

Ccontainer::Ccontainer(Vector2D pos, int width, int height, std::string text) : 
	Entity("", pos, Vector2D(0, 0), width, height, 0, 0, 0, 0.0, 0) {
	m_name = "Ccontainer";
	m_text = text;
}

void Ccontainer::addEntity(Entity* e) {
	//position of entities are relative to container position.
	e->m_position += m_position;

	entities.push_back(e);
}