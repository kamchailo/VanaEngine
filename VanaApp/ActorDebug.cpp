#include "ActorDebug.h"

#include <imgui/imgui.h>
#include <iostream>


ActorDebug::~ActorDebug()
{
}

void ActorDebug::Draw()
{
	ImGui::Text(text1.c_str());
	//std::cout << text1 << "  " << text2 << "|";
	ImGui::Text(text2.c_str());
	ImGui::Text(text3.c_str());
	ImGui::Text(text4.c_str());
	ImGui::Text(text5.c_str());
}

void ActorDebug::SetText1(std::string _text)
{
	text1 = _text;
}

void ActorDebug::SetText2(std::string _text)
{
	text2 = _text;
}

void ActorDebug::SetText3(std::string _text)
{
	text3 = _text;
}

void ActorDebug::SetText4(std::string _text)
{
	text4 = _text;
}

void ActorDebug::SetText5(std::string _text)
{
	text5 = _text;
}