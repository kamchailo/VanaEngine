#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Logger.h"

class GraphicSystem
{
public:
	static GraphicSystem* GetInstance() {
		static GraphicSystem* instance = new GraphicSystem();
		return instance;
	}
	~GraphicSystem();
	int Init(int width, int height);
	int GraphicUpdate();
	int GraphiceSwapBuffer();
	GLFWwindow* GetWindow();
	inline static glm::vec2 windowSize;
private:
	GraphicSystem();
	static GraphicSystem* _instance;
	GLFWwindow* window;
	Logger* logGraphic;
};