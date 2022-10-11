#include "pch.h"
#include "Input.h"
#include "Graphics.h"

Input::Input()
{
}

Input::~Input()
{
	delete(logInput);
}

void Input::Init()
{
	logInput = new Logger("Input");
	// need fixing
	//glfwSetWindowUserPointer(GraphicSystem::GetInstance()->GetWindow(), this);
	//glfwSetKeyCallback(GraphicSystem::GetInstance()->GetWindow(), KeyboardCallback);
}

// might need to move to outside class
void Input::KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// can be make outside class to send as callback
	if (glfwGetKey(GraphicSystem::GetInstance()->GetWindow(), GLFW_KEY_W))
	{
		logInput->Log(LOG_INFO, "W is pressed.");
	}
}

void Input::Update()
{
}

int Input::isPressed(unsigned int key)
{

	return 0;
}

int Input::isHold(unsigned int key)
{
	return 0;
}
