#pragma once

class GLFWwindow;

namespace Vana
{
	class Window
	{
	public:
		Window(int _width, int _height);
		~Window();
		void MakeContextCurrent();
		int ShouldClose();
		glm::vec2 GetSize() const;

		// Window Size Callback
		void framebuffer_size_callback(GLFWwindow* _window, int _width, int _height);
	private:
		GLFWwindow* window;
		inline static glm::vec2 windowSize;
	};
}