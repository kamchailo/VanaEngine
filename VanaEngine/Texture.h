#pragma once
#include <stb/stb_image.h>

class Texture
{
public:
	Texture(char* texturePath, bool alpha);
	Texture(const char* texturePath, bool alpha);
	~Texture();
	void Bind(int unit);
	unsigned int ID;
private:
};