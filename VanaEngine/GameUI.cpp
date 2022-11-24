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

 //   ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

 //   ImGui::Text("This is some useful text.");  
 //   ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
 //   
	//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

	//if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
	//	counter++;
	//ImGui::SameLine();
	//ImGui::Text("counter = %d", counter);

	//ImGui::End();

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