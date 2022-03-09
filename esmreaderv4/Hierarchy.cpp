#include "Hierarchy.h"
#include "game.h"

Hierarchy::Hierarchy(Vector2D pos, int width, int height) :
	Entity("", pos, Vector2D(0, 0), width, height, 0, 0, 0, 0.0, 0) {
	m_name = "Hierarchy";
	ctree = new Ctreeview(Vector2D(0, 20), m_width, m_height);

	//fill the tree view control with data
	for (int i = 0; i < Game::Instance()->vcell.size(); i++) {
		std::vector<std::string> velements;
		for (int j = 0; j < Game::Instance()->vcell[i].persistentRefs.size(); j++) {
			velements.push_back(Game::Instance()->vcell[i].persistentRefs[j].name);
		}

		std::string str = Game::Instance()->vcell[i].name;
		if (str == "")
			ctree->addData(to_string(i) + " (no name) " + Game::Instance()->vcell[i].regionName, velements);
		else
			ctree->addData(to_string(i) + Game::Instance()->vcell[i].name, velements);
	}
	ctree->setData();
}

Hierarchy::~Hierarchy() {
	delete(ctree);
}

void Hierarchy::handleEvents() {
	ctree->handleEvents();
}

void Hierarchy::update() {

}

void Hierarchy::draw() {
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
	ctree->draw();

	//restore the render rect.
	SDL_RenderSetClipRect(Game::Instance()->getRenderer(), actualClipRect);
	delete(actualClipRect);
	delete(containerRect);
}

