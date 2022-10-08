#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class GraphicSystem
{
public:
	~GraphicSystem();
	int Init(int width, int height);
	int GraphicUpdate();
	int GraphiceSwapBuffer();
	GLFWwindow* GetWindow();
	inline static glm::vec2 windowSize;
private:
	GLFWwindow* window;
};