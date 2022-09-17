#pragma once
#include "PlayableCharacter.h"

class Bob : public PlayableCharacter
{
public:
	// Constructor
	Bob();

	// Override Input Handler
	bool virtual handleInput();
};

