#include "pch.h"
#include "GameUI.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

Vana::GameUI::GameUI(GLFWwindow* _window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& GameUIIO = ImGui::GetIO(); (void)GameUIIO;
	GameUIIOPtr = &GameUIIO;
	ImGui::StyleColorsDark();

	window = _window;

	ImGui_ImplGlfw_InitForOpenGL(_window, true);
	//const char* glsl_version = "#version 330";
	ImGui_ImplOpenGL3_Init("#version 330");
}

Vana::GameUI::~GameUI()
{
}

void Vana::GameUI::Update()
{   
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	for (auto * u : uiWindows)
	{
		ImGui::Begin(u->GetName().c_str());
		ImGui::PushItemWidth(u->GetWidth());
		u->Draw();
		ImGui::End();
	}


	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Vana::GameUI::AddUiWindow(GameUIWindow* _ui)
{
	uiWindows.push_back(_ui);
}