#include "pch.h"
#include "Graphics.h"

void processInput(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

GraphicSystem::~GraphicSystem()
{
	delete(logGraphic);
	glfwTerminate();
}

int GraphicSystem::Init(int width, int height)
{
	logGraphic = new Logger("Graphics");
	windowSize = glm::vec2(width, height);
	//std::cout << ">> 1. GLFW INIT" << std::endl;
	// ================================
	//			  Init GLFW
	// ================================
	glfwInit();
	// SET OpenGL Version to 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// SET OpenGL Version to X.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// SET OpenGL Profile to CORE_PROFILE -- more subset of OpenGL Features
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ================================

	//std::cout << ">> 2. Create window" << std::endl;
	// ================================
	//			Create Windows
	// ================================
	window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		logGraphic->Log(LOG_ERROR, "Fail to Create GLFW window");
		//std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return 1;
	}
	else
	{
		logGraphic->Log(LOG_INFO, "GLFWwindow created");
		//std::cout << "GLFWwindow created" << std::endl;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	// ================================
	
	//std::cout << ">> 3. GLAD Init" << std::endl;
	// ================================
	//			  GLAD Init
	// ================================
	// glad : load all OpenGL function pointers (to fit current environment)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		logGraphic->Log(LOG_ERROR, "Failed to initialize GLAD");
		//std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	else
	{
		logGraphic->Log(LOG_INFO, "GLAD Initialized");
		//std::cout << "GLAD Initialized" << std::endl;
	}
	// use glad to help create viewport ; glad connect to os
	//glViewport(0, 0, 800, 600); >> put in callback
	// ================================
	
	// Everything is ok
	return 0; 
}

int GraphicSystem::GraphicUpdate()
{
	if (glfwWindowShouldClose(window))
	{
		return 1;
	}
	// input
	processInput(window);
	// Rendering Commands vvv
	glClearColor(0.0f, 1.0f, 0.7f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	return 0;
}

int GraphicSystem::GraphiceSwapBuffer()
{
	// glfw : swap buffers and poll IO events
	glfwSwapBuffers(window);
	glfwPollEvents();
	return 0;
}

GLFWwindow* GraphicSystem::GetWindow()
{
	return window;
}

GraphicSystem::GraphicSystem()
{
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	GraphicSystem::windowSize = glm::vec2(width, height);
}