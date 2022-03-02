#include "Inspector.h"
#include "game.h"

Inspector::Inspector(Vector2D pos, int width, int height) :
	Entity("", pos, Vector2D(0, 0), width, height, 0, 0, 0, 0.0, 0) {
	m_name = "Inspector";
}

void Inspector::handleEvents() {

}

void Inspector::update() {

}

void Inspector::draw() {
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

	//draw the things
	AssetsManager::Instance()->Text(m_name, "font", m_position.m_x, m_position.m_y, SDL_Color({ 255,255,255,0 }), Game::Instance()->getRenderer());
	std::string temp = "";
	if (hierarchy->ctree->data.size() > 0 && hierarchy->ctree->selected != -1)
	{
		if (hierarchy->ctree->data[hierarchy->ctree->selected].element == -1)
		{
			temp += "Cell: " + to_string(hierarchy->ctree->data[hierarchy->ctree->selected].cell);
		}
		else
		{
			temp += "Cell: " + to_string(hierarchy->ctree->data[hierarchy->ctree->selected].cell);
			temp += " Element: " + to_string(hierarchy->ctree->data[hierarchy->ctree->selected].element);
		}
		AssetsManager::Instance()->Text(temp, "font", m_position.m_x, m_position.m_y + 20, SDL_Color({ 255,255,255,0 }), Game::Instance()->getRenderer());
	}

	//restore the render rect.
	SDL_RenderSetClipRect(Game::Instance()->getRenderer(), actualClipRect);
	delete(actualClipRect);
	delete(containerRect);
}
