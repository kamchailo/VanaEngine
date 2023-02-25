#pragma once

#include "../Utilities/Logger.h"

class GLFWwindow;

#define MAX_KEYS 400

enum InputAction
{
	INPUT_KEY_LEFT,
	INPUT_KEY_RIGHT,
	INPUT_KEY_UP,
	INPUT_KEY_DOWN,
	INPUT_KEY_INTERACT,
	INPUT_KEY_RESET
};

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
	void SetKeyToAction(unsigned int key, InputAction action);
	unsigned int GetKeyFromAction(InputAction action);
	void UpdateIsPressedArray(unsigned int key, int action);
	bool IsPressed(InputAction action);
	bool IsHold(InputAction action);
	void Log(LoggerGroup, std::string);
private:
	Input();
	Logger* logInput;
	std::map<InputAction, unsigned int> actionKeyMap;
	bool isPressedArray[MAX_KEYS];
	bool previousIsPressedArray[MAX_KEYS];
};

void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);