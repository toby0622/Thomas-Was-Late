#pragma once

#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder {
private:
	// STL map container which holds related pairs of "String" and "Texture"
	std::map<std::string, sf::Texture> m_Textures;

	// pointer of the same type as the class itself
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};

#endif