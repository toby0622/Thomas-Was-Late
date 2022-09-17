#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	// Constructor
	Thomas();

	// Override Input Handler
	bool virtual handleInput();
};
