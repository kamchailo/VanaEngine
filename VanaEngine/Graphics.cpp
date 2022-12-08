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
	viewScale = glm::vec2(1.0);
	viewMatrix = glm::scale(glm::mat4(1), glm::vec3((2.0f * viewScale.x) / windowSize.x, (2.0f * viewScale.y) / windowSize.y, 1.0));
	//std::cout << ">> 1. GLFW INIT" << std::endl;
	// ================================
	//			  Init GLFW
	// ================================
	glfwInit();
	// SET OpenGL Version to 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// SET OpenGL Version to X.3 // change to 3.0 support imgui
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// SET OpenGL Profile to CORE_PROFILE -- more subset of OpenGL Features
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// ================================

	//std::cout << ">> 2. Create window" << std::endl;
	// ================================
	//			Create Windows
	// ================================
	window = glfwCreateWindow(width, height, "Vana Engine", NULL, NULL);
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

	// Call window.MakeContextCurrent()
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

	// GL ENABLE
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	opaqueComponents.reserve(20);

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
	// change viewMat
	viewMatrix = glm::scale(glm::mat4(1), glm::vec3((2.0f * viewScale.x) / windowSize.x, (2.0f * viewScale.y) / windowSize.y, 1.0));
	// Rendering Commands vvv
	glClearColor(backgroundColor.r, backgroundColor.g, backgroundColor.b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	return 0;
}

void GraphicSystem::DrawScene()
{
	// Draw Opaque
	glEnable(GL_DEPTH_TEST);
	for (auto& o : opaqueComponents)
	{
		o->Draw();
	}
	// Sort Alpha to multimap
	// Draw Alpha
	glDisable(GL_DEPTH_TEST);
	for (auto& a : alphaComponents)
	{
		a.second->Draw();
	}
	// Clear multimap contains alpha
	opaqueComponents.clear();
	alphaComponents.clear();
}

int GraphicSystem::GraphiceSwapBuffer()
{
	// glfw : swap buffers and poll IO events
	glfwSwapBuffers(window);
	glfwPollEvents();
	return 0;
}

void GraphicSystem::RegisterOpaqueComponent(ComponentRenderer* _comp)
{
	opaqueComponents.push_back(_comp);
}

void GraphicSystem::RegisterAlphaComponent(float _depth, ComponentRenderer* _comp)
{
	alphaComponents.insert(std::pair(_depth, _comp));
}

void GraphicSystem::SetBackgroundColor(glm::vec3 _color)
{
	backgroundColor = _color;
}

void GraphicSystem::SetViewScale(glm::vec2 _scale)
{
	viewScale = _scale;
}

GLFWwindow* GraphicSystem::GetWindow()
{
	return window;
}

glm::mat4 GraphicSystem::GetviewMatrix() const
{
	return viewMatrix;
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