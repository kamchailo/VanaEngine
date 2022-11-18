#pragma once

class GLFWwindow;
class ImGuiIO;

namespace Vana
{
	class GameUI
	{
	public:
		GameUI(GLFWwindow* _window);
		~GameUI();

		void Update();

	private:

		GLFWwindow* window;
		ImGuiIO* GameUIIOPtr;

		// test
		float clear_color[3] = {0.0, 0.0, 0.0};
		float f = 0;
		int counter = 0;
	};

	class GameUIWindow
	{
	public:
		GameUIWindow(int _width, int _height);
	private:
		void Draw();
	};
}