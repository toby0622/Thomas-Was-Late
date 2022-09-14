#include "TextureHolder.h"
#include <assert.h>
using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder() {
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename) {
	// reference to "m_Textures" using "m_S_Instance"
	auto& m = m_s_Instance -> m_Textures;

	// auto is the equivalent of map<string, Texture>
	// create an iterator to hold a key-value-pair and search for the required pair using the passed-in file name
	auto keyValuePair = m.find(filename);

	// auto is equivalent of map<string, Texture>::iterator
	// find the match
	if (keyValuePair != m.end()) {
		// find, return the texture, the second part of the pair
		return keyValuePair -> second;
	} else {
		// file not found, create a new key value pair using the filename
		auto& texture = m[filename];

		// load the texture from file
		texture.loadFromFile(filename);

		return texture;
	}
}