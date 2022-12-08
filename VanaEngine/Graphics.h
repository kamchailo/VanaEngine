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
	void SetBackgroundColor(glm::vec3 _color);
	void SetViewScale(glm::vec2 _scale);
	GLFWwindow* GetWindow();
	glm::mat4 GetviewMatrix() const;
	inline static glm::vec2 windowSize;
private:
	GraphicSystem();
	static GraphicSystem* _instance;
	GLFWwindow* window;
	Logger* logGraphic;
	glm::mat4 viewMatrix;
	glm::vec2 viewScale;
	glm::vec3 backgroundColor = glm::vec3(0.0,1.0,0.7);
};