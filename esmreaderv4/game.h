#pragma once

#include <vector>
#include <list>
#include <SDL.h>
#include <SDL_image.h>
#include "Vector2D.h"
#include "AssetsManager.h"
#include "InputHandler.h"
#include "esmreader.h"
#include "Entity.h"
#include "Clabel.h"
#include "Ctreeview.h"
#include "Ccontainer.h"
#include "Hierarchy.h"
#include "Inspector.h"

////Game States
enum GAMESTATES {SPLASH, MENU, LOAD_LEVEL, GAME, END_GAME};

class Game {
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	
	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();

	bool running() { return m_bRunning; }

	int getGameWidth() const { return m_gameWidth; }
	int getGameHeight() const { return m_gameHeight; }

	void UpdateHiScores(int newscore);
	void ReadHiScores();
	void WriteHiScores();

	bool mouseClicked = false;
	Vector2D mousepos;
	std::string lastButtonClicked = "";
	ShowControl* showControl;

	//vectors with game data
	std::vector<GMST> vgmst; //vector of game settings
	std::vector<GLOB> vglob; //vector of global values
	std::vector<CLAS> vclas;  //vector of character classes
	std::vector<FACT> vfact;
	std::vector<RACE> vrace;
	std::vector<SOUN> vsoun;
	std::vector<SKIL> vskil;
	std::vector<MGEF> vmgef;
	std::vector<SCPT> vscpt;
	std::vector<REGN> vregn;
	std::vector<BSGN> vbsgn;
	std::vector<LTEX> vltex;
	std::vector<STAT> vstat;
	std::vector<DOOR> vdoor;
	std::vector<MISC> vmisc;
	std::vector<WEAP> vweap;
	std::vector<CONT> vcont;
	std::vector<SPEL> vspel;
	std::vector<CREA> vcrea;
	std::vector<BODY> vbody;
	std::vector<LIGH> vligh;
	std::vector<ENCH> vench;
	std::vector<NPC_> vnpc_;
	std::vector<ARMO> varmo;
	std::vector<CLOT> vclot;
	std::vector<REPA> vrepa;
	std::vector<ACTI> vacti;
	std::vector<APPA> vappa;
	std::vector<LOCK> vlock;
	std::vector<PROB> vprob;
	std::vector<INGR> vingr;
	std::vector<BOOK> vbook;
	std::vector<ALCH> valch;
	std::vector<LEVI> vlevi;
	std::vector<LEVC> vlevc;
	std::vector<CELL> vcell; //vector of game cells
	std::vector<LAND> vland;
	std::vector<PGRD> vpgrd;
	std::vector<SNDG> vsndg;
	std::vector<DIAL> vdial;

private:
	Game();
	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int state = -1;
	std::vector<int> vhiscores;
	int lives, score;

	std::list<Entity*> entities;
	bool isCollide(Entity *a, Entity *b);
	bool isCollideRect(Entity *a, Entity *b);

	/*Ccontainer* hierarchy =  nullptr;
	Ccontainer* inspector = nullptr;*/
	Hierarchy* hierarchy = nullptr;
	Inspector* inspector = nullptr;

	bool m_bRunning;
	int m_gameWidth;
	int m_gameHeight;
};