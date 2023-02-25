#pragma once

class Texture
{
public:
	Texture(char* texturePath);
	Texture(const char* texturePath);
	~Texture();
	void Bind(int unit);
	bool Alpha() const;
	unsigned int ID;
private:
	bool alpha;
};