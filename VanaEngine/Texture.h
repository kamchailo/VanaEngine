#pragma once
#include <stb/stb_image.h>

class Texture
{
public:
	Texture(char* texturePath);
	Texture(const char* texturePath);
	~Texture();
	unsigned int ID;
private:
};