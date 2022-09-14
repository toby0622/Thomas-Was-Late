#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
using namespace sf;

class Engine {
private:
	// texture holder
	TextureHolder th;
	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// gravity force pushing the characters down
	const int GRAVITY = 300;

	RenderWindow m_Window;

	View m_MainView;
	View m_LeftView;
	View m_RightView;

	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;
	View m_HudView;

	// a "Sprite" and a "Texture" for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// game currently playing
	bool m_Playing = false;

	// character 1 or 2 currently focusing
	bool m_Character1 = true;

	// full screen mode (not split)
	bool m_SplitScreen = false;

	// time left (in seconds)
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// new level
	bool m_NewLevelRequired = true;

	// private internal functions
	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();

	// private function call
	void run();
};