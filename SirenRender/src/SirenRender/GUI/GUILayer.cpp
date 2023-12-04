#include "srpch.h"
#include "GUILayer.h"

#include "imgui.h"
#include "SirenRender/Platform/OpenGL/ImGuiOpenGLRender.h"

#include "glfw3.h"
#include "SirenRender/Application.h"

namespace SirenRender
{
	GUILayer::GUILayer()
		: Layer("GUILayer")
	{

	}

	GUILayer::~GUILayer()
	{

	}

	void GUILayer::OnDetach()
	{
		
	}

	void GUILayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void GUILayer::OnUpdate()
	{

		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::GetInstance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());


		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		//ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void GUILayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<Mouse>
	}

	bool GUILayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& event)
	{
		return false;
	}

	bool GUILayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event)
	{
		return false;
	}

	bool GUILayer::OnMouseMovedEvent(MouseMovedEvent& event)
	{
		return false;
	}

	bool GUILayer::OnMouseScrolledEvent(MouseScrolledEvent& event)
	{
		return false;
	}

	bool GUILayer::OnKeyPressedEvent(KeyPressedEvent& evnet)
	{
		return false;
	}

	bool GUILayer::OnKeyReleasedEvent(KeyReleasedEvent& evnet)
	{
		return false;
	}

	bool GUILayer::OnWindowResizeEvent(WindowResizeEvent& event)
	{
		return false;
	}
}