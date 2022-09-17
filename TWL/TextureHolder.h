#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H
#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	// STL map container (String & Texture Pair)
	std::map<std::string, sf::Texture> m_Textures;

	// Class Instance Pointer
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif
