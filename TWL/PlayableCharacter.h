#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class PlayableCharacter
{
protected:
	// Sprite
	Sprite m_Sprite;

	// Jump Duration Time
	float m_JumpDuration;

	// Character Operation (Jump of Fall)
	bool m_IsJumping;
	bool m_IsFalling;

	// Currently Moving Direction
	bool m_LeftPressed;
	bool m_RightPressed;

	// Jump Time Passed
	float m_TimeThisJump;

	// Jump Initialize
	bool m_JustJumped = false;

private:
	// Gravity
	float m_Gravity;

	// Character Movement Speed
	float m_Speed = 400;

	// Character Position
	Vector2f m_Position;

	// Body Parts
	FloatRect m_Feet;
	FloatRect m_Head;
	FloatRect m_Right;
	FloatRect m_Left;

	Texture m_Texture;

public:
	void spawn(Vector2f startPosition, float gravity);

	// Pure Virtual Function (Abstract and couldn't be Instanciated)
	bool virtual handleInput() = 0;

	// Player Position
	FloatRect getPosition();

	// Position of Different Part Sprites
	FloatRect getFeet();
	FloatRect getHead();
	FloatRect getRight();
	FloatRect getLeft();

	Sprite getSprite();

	// Stand Still
	void stopFalling(float position);
	void stopRight(float position);
	void stopLeft(float position);
	void stopJump();

	// Character Center
	Vector2f getCenter();

	void update(float elapsedTime);
};
