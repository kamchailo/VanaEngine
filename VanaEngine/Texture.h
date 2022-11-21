#pragma once
#include <stb/stb_image.h>

class Texture
{
public:
	Texture(char* texturePath);
	Texture(const char* texturePath);
	~Texture();
	void Bind(int unit);
	unsigned int ID;
private:
};