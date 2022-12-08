#include "pch.h"
#include "Input.h"
#include "Graphics.h"

Input::Input()
{
	logInput = new Logger("Input");
}

Input::~Input()
{
	delete(logInput);
}

void Input::Init()
{
	glfwSetWindowUserPointer(GraphicSystem::GetInstance()->GetWindow(), this);
	glfwSetKeyCallback(GraphicSystem::GetInstance()->GetWindow(), KeyboardCallback);
	// @@ Default to test
	this->SetKeyToAction(GLFW_KEY_UP, INPUT_KEY_UP);
	this->SetKeyToAction(GLFW_KEY_DOWN, INPUT_KEY_DOWN);
	this->SetKeyToAction(GLFW_KEY_LEFT, INPUT_KEY_LEFT);
	this->SetKeyToAction(GLFW_KEY_RIGHT, INPUT_KEY_RIGHT);
	this->SetKeyToAction(GLFW_KEY_SPACE, INPUT_KEY_INTERACT);
	this->SetKeyToAction(GLFW_KEY_R, INPUT_KEY_RESET);
	for (int i = 0; i < MAX_KEYS; i++)
	{
		isPressedArray[i] = false;
		previousIsPressedArray[i] = false;
	}
}


void Input::Update()
{
	for (int i = 0; i < MAX_KEYS; i++)
	{
		previousIsPressedArray[i] = isPressedArray[i];
		//isPressedArray[i] = false;
	}
}

void Input::SetKeyToAction(unsigned int key, InputAction action)
{
	actionKeyMap[action] = key;
}

unsigned int Input::GetKeyFromAction(InputAction action)
{
	return actionKeyMap[action];
}

void Input::UpdateIsPressedArray(unsigned int key, int action)
{
	isPressedArray[key] = static_cast<bool>(action);
}

bool Input::IsPressed(InputAction action)
{
	return isPressedArray[GetKeyFromAction(action)];
}

// @@ Need fixing isHold
bool Input::IsHold(InputAction action)
{
	return isPressedArray[GetKeyFromAction(action)] && previousIsPressedArray[GetKeyFromAction(action)];
}

void Input::Log(LoggerGroup logGroup, std::string str)
{
	logInput->Log(logGroup, str);
}

// @@ This might cause problem later as global function
void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_UNKNOWN)
	{
		Input::GetInstance()->Log(LOG_WARNING, "KEY UNKNOWN");
		return;
	}
	Input::GetInstance()->UpdateIsPressedArray(key, action);
}