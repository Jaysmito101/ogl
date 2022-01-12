#define _CRT_SECURE_NO_WARNINGS
#include <Base.h>
#include <implot/implot.h>
#include <EntryPoint.h>
#include <glm/ext/quaternion_trigonometric.hpp>
#include <string>
#include <glm/gtc/constants.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext/matrix_relational.hpp>
#include <glm/ext/vector_relational.hpp>
#include <glm/ext/scalar_relational.hpp>

#include <time.h>
#include <string.h>
#include <mutex>
#include <sys/stat.h>
#include <dirent/dirent.h>
#include <atomic>

static Application* myApp;

static void OnBeforeImGuiRender() {

	static bool dockspaceOpen = true;
	static bool opt_fullscreen_persistant = true;
	bool opt_fullscreen = opt_fullscreen_persistant;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (opt_fullscreen)
	{
		ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.1f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
	ImGui::PopStyleVar();
	if (opt_fullscreen) {
		ImGui::PopStyleVar(2);
	}
	// DockSpace
	ImGuiIO& io = ImGui::GetIO();
	ImGuiStyle& style = ImGui::GetStyle();
	float minWinSizeX = style.WindowMinSize.x;
	style.WindowMinSize.x = 370.0f;
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	}

	style.WindowMinSize.x = minWinSizeX;

	//ShowMenu();
}

static void OnImGuiRenderEnd() {
	ImGui::End();
}
#include <iostream>
class MyApp : public Application
{
public:
	virtual void OnPreload() override {
		SetTitle("TerraForge3D - Jaysmito Mukherjee");
		std::cout << "PreLoad\n";
		
	}

	virtual void OnUpdate(float deltatime) override
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		RenderImGui();
	}

	virtual void OnOneSecondTick() override
	{
		std::cout << "SecondTick\n";	
	}

	virtual void OnImGuiRender() override
	{
		OnBeforeImGuiRender();
		
		ImGui::Begin("Hi");
		ImGui::Text("Hello World!");
		ImGui::End();
	
		ImGui::ShowDemoWindow();
		ImPlot::ShowDemoWindow();

		OnImGuiRenderEnd();
	}

	virtual void OnStart(std::string loadFile) override
	{
		srand((unsigned int)time(NULL));
		std::cout << "Start\n";
	}

	void OnEnd()
	{
	}
};

Application* CreateApplication()
{
	myApp = new MyApp();
	return myApp;
}