#pragma once

#include <string>
#include <UI/GameUIWindow.h>

class ActorDebug : public GameUIWindow
{
public:
	ActorDebug(std::string _name, int _width, int _height)
		:GameUIWindow(_name, _width, _height)
	{};
	virtual ~ActorDebug();
	virtual void Draw() override;
	void SetText1(std::string _text);
	void SetText2(std::string _text);
	void SetText3(std::string _text);
	void SetText4(std::string _text);
	void SetText5(std::string _text);
private:
	std::string text1 = "";
	std::string text2 = "";
	std::string text3 = "";
	std::string text4 = "";
	std::string text5 = "";
};