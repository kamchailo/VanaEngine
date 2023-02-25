#pragma once

#include "GameUI.h"

class GameUIWindow
{
public:
	GameUIWindow(std::string _name, int _width, int _height)
		: name(_name)
		, width(_width)
		, height(_height)
	{};
	virtual ~GameUIWindow() {};

	std::string GetName() const { return name; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }
	//void AddText(const char* fmt, ...);
private:
	friend Vana::GameUI;
	virtual void Draw() = 0;
	std::string name;
	int width;
	int height;
};