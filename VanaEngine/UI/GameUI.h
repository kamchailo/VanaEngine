#pragma once

#include <vector>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

class GameUIWindow;

namespace Vana
{
	class GameUI
	{
	public:
		GameUI(GLFWwindow* _window);
		~GameUI();

		void Update();

		void AddUiWindow(GameUIWindow* _ui);

	private:

		GLFWwindow* window;
		ImGuiIO* GameUIIOPtr;

		std::vector<GameUIWindow*> uiWindows;

		// test
		float clear_color[3] = {0.0, 0.0, 0.0};
		float f = 0;
		int counter = 0;
	};
}