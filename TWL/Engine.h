#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "HUD.h"
#include "ParticleSystem.h"
using namespace sf;

class Engine
{
private:
	// Texture Holder
	TextureHolder th;

	// Particle System Create
	ParticleSystem m_PS;

	// Player (Thomas & Bob)
	Thomas m_Thomas;
	Bob m_Bob;

	// LevelManager
	LevelManager m_LM;

	// SoundManager
	SoundManager m_SM;

	// HUD
	Hud m_Hud;
	int m_FramesSinceLastHUDUpdate = 0;
	int m_TargetFramesPerHUDUpdate = 500;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// Gravity Force
	const int GRAVITY = 300;

	RenderWindow m_Window;

	View m_MainView;
	View m_LeftView;
	View m_RightView;

	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Background (Sprite & Texture)
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Background Shader
	Shader m_RippleShader;

	// Game Playing State
	bool m_Playing = false;

	// Camera Focus (Character)
	bool m_Character1 = true;

	// Screen Mode (Single or Multiplayer)
	bool m_SplitScreen = false;

	// Level Time Left
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;

	// New Level Startup
	bool m_NewLevelRequired = true;

	// Level Design VertexArray
	VertexArray m_VALevel;

	// 2D Array Map (Pointer of Pointer)
	int** m_ArrayLevel = NULL;

	// Background & Level Tile Texture
	Texture m_TextureTiles;
	
	void input();
	void update(float dtAsSeconds);
	void draw();	

	// New Level Loaded
	void loadLevel();

	bool detectCollisions(PlayableCharacter& character);
	
	// Directional Sound
	void populateEmitters(vector <Vector2f>& vSoundEmitters, int** arrayLevel);

	// Fire Emitter Location
	vector <Vector2f> m_FireEmitters;
	
public:
	// Constructor
	Engine();

	void run();
};
