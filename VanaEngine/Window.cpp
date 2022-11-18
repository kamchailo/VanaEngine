#include "pch.h"
#include "Window.h"

Vana::Window::Window(int _width, int _height)
{
	window = glfwCreateWindow(_width, _height, "Vana Engine", NULL, NULL);
}

Vana::Window::~Window()
{
	delete window;
}

void Vana::Window::MakeContextCurrent()
{
	glfwMakeContextCurrent(window);
	//GLFWframebuffersizefun func = framebuffer_size_callback;
	//glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

int Vana::Window::ShouldClose()
{
	return glfwWindowShouldClose(window);
}

glm::vec2 Vana::Window::GetSize() const
{
	return glm::vec2();
}

void Vana::Window::framebuffer_size_callback(GLFWwindow* _window, int _width, int _height)
{
	glViewport(0, 0, _width, _height);
	windowSize = glm::vec2(_width, _height);
}

