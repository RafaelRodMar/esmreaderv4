#include "Ccontainer.h"
#include "game.h"

void Ccontainer::handleEvents() {
	for (auto i : entities)
		i->handleEvents();
}

void Ccontainer::update(){
	for (auto i : entities)
		i->update();
}

void Ccontainer::draw(){
	//container don't allow to draw outside of it
	SDL_Rect* actualClipRect = new SDL_Rect();
	SDL_RenderGetClipRect(Game::Instance()->getRenderer(), actualClipRect);

	//set the drawing zone to only inside container
	SDL_Rect* containerRect = new SDL_Rect();
	containerRect->x = m_position.m_x;
	containerRect->y = m_position.m_y;
	containerRect->w = m_width;
	containerRect->h = m_height;
	//only what is inside labelRect will be drawn
	SDL_RenderSetClipRect(Game::Instance()->getRenderer(), containerRect);

	//set background color for the container
	SDL_SetRenderDrawColor(Game::Instance()->getRenderer(), 56, 56, 56, 0);
	SDL_Rect* rect = new SDL_Rect();
	rect->x = m_position.m_x;
	rect->y = m_position.m_y;
	rect->w = m_width;
	rect->h = m_height;
	SDL_RenderFillRect(Game::Instance()->getRenderer(), rect);
	delete(rect);

	for (auto i : entities)
		i->draw();

	//restore the render rect.
	SDL_RenderSetClipRect(Game::Instance()->getRenderer(), actualClipRect);
	delete(actualClipRect);
	delete(containerRect);
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
	//add the position plus height of the last entity
	if (entities.size() > 0)
	{
		e->m_position.m_y += entities.back()->m_position.m_y;
		e->m_position.m_y += entities.back()->m_height;
	}

	entities.push_back(e);
}