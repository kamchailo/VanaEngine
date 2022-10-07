#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class GraphicSystem
{
public:
	~GraphicSystem();
	int Init();
	int GraphicUpdate();
	int GraphiceSwapBuffer();
	GLFWwindow* GetWindow();
private:
	GLFWwindow* window;
};