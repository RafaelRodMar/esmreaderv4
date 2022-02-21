#pragma once
#include <sdl.h>
#include <string>
#include "Vector2D.h"
#include "AssetsManager.h"

class Game;

class Entity
{
public:
	//movement variables
	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	//size variables
	int m_width = 0, m_height = 0;

	//animation variables
	int m_currentRow = 0;
	int m_currentFrame = 0;
	int m_numFrames = 0;
	std::string m_textureID;

	//common boolean variables
	bool m_bUpdating = false;
	bool m_bDead = false;
	bool m_bDying = false;

	//rotation
	double m_angle = 0;

	//blending
	int m_alpha = 255;

	//game variables
	int m_radius = 1;
	bool m_life;
	bool m_shield;
	int m_shieldTime;
	int m_waitTime = 0;
	std::string m_name;

	Entity()
	{
		m_life = true;
		m_shield = false;
	}

	void settings(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames, int row, int cframe, double Angle, int radius)
	{
		m_textureID = Texture;
		m_position = pos;
		m_velocity = vel;
		m_width = Width; m_height = Height;
		m_angle = Angle;
		m_radius = radius;
		m_numFrames = nFrames;
		m_currentRow = row;
		m_currentFrame = cframe;
	}

	virtual void handleEvents();
	virtual void update();
	virtual void draw();

	virtual ~Entity() {};
};

class car : public Entity
{
public:
	car()
	{
		m_name = "car";
	}

	void update();
};


class asteroid : public Entity
{
public:
	asteroid()
	{
		m_velocity.m_x = rand() % 8 - 4;
		m_velocity.m_y = rand() % 8 - 4;
		m_name = "asteroid";
	}

	void  update();

};

class bullet : public Entity
{
public:
	bullet()
	{
		m_name = "bullet";
	}

	void update();
	void draw();
};


class player : public Entity
{
public:

	player()
	{
		m_name = "player";
	}

	void update();
	void draw();
	void handleEvents();

};

class Button : public Entity{
	public:

	std::string m_text = "";
	std::string m_font = "";

	Button(){
		m_name = "Button";
	}

	void buttonSettings(const string &Texture, Vector2D pos, Vector2D vel, int Width, int Height, int nFrames, 
						int row, int cframe, double Angle, int radius, std::string text, std::string font, bool autoSize);

	void update();
	void draw();
	void handleEvents();

	void autoSize();
	bool mouseOver = false;
};

class ShowControl : public Entity {
public:
	int xinit = 0;
	int yinit = 150;
	std::string tag = "";
	std::vector<std::string> headers;
	std::vector<int> sizes; //size of the columns
	int totalWidth = 0;
	std::vector< std::vector<std::string> > data;
	int dataFrom = 0;
	int dataTo = 0;
	bool showHScroll = false;
	bool showVScroll = false;
	bool mouseOn = false;
	Vector2D mouseOver;
	int selected = -1;
	int selectedIndex = -1;
	int textureColumn = -1;
	std::string textureId = "";
	int iconColumn = -1;
	std::string iconId = "";
	int soundColumn = -1;
	std::string soundId = "";

	ShowControl() {
		xinit = m_position.m_x;
		yinit = m_position.m_y;
	}

	void update();
	void draw();
	void handleEvents();

	void reset() {
		//clear the vectors and give them size 0 swapping with a empty vector.
		std::string tag = "";
		std::vector<std::string>().swap(headers);
		std::vector< std::vector<std::string> >().swap(data);
		std::vector<int>().swap(sizes);
		xinit = m_position.m_x = 0;
		yinit = m_position.m_y = 150;
		totalWidth = 0;
		dataFrom = dataTo = 0;
		showHScroll = showVScroll = false;
		mouseOn = false;
		textureColumn = -1;
		AssetsManager::Instance()->clearFromTextureMap(textureId);
		textureId = "";
		iconColumn = -1;
		AssetsManager::Instance()->clearFromTextureMap(iconId);
		iconId = "";
		soundColumn = -1;
		AssetsManager::Instance()->clearSound(soundId);
		soundId = "";
		selected = -1;
		selectedIndex = -1;
	}
	
	void setData(std::vector<std::string>& h, std::vector< std::vector<std::string> >& d);
};

