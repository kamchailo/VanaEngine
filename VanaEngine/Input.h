#pragma once
#include "pch.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Logger.h"

class Input
{
public:
	~Input();
	static Input* GetInstance()
	{
		static Input* instance = new Input();
		return instance;
	}
	void Init();
	void Update();
	void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	int isPressed(unsigned int key);
	int isHold(unsigned int key);
private:
	Input();
	Logger* logInput;
	// map<GL_KEY, status> -1 release 0 1 pressed
	std::map<unsigned int, int> keyStatus;
};