#include "srpch.h"
#include "glad/glad.h"
#include "Application.h"
#include "glfw3.h"
#include "Render/RenderCommand.h"
#include "Render/Renderer.h"
#include "imgui.h"

namespace SirenRenderer
{

	Application* Application::s_Instance = nullptr;
	
	Application::Application(const ApplicationProps& props)
	{  
		SR_CORE_ASSERTS(!s_Instance, "Application already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create(WindowProps(props.Name, props.WindowWidth, props.WindowHeight)));
		m_Window->SetEventCallBack(SR_BIND_EVENT_FUNC(Application::OnEvent));
		m_Window->SetVSync(false);

		m_GuiLayer = new GUILayer("ImGuiLayer");
		PushOverlay(m_GuiLayer);

		Renderer::Init();
		//Renderer::WaitAndRender();
	}

	Application:: ~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverLay(layer);
		layer->OnAttach();
	}

	void Application::RenderGui()
	{
		m_GuiLayer->Begin();

		ImGui::Begin("Renderer");
		auto& caps = RendererAPI::GetCapabilities();
		ImGui::Text("Vendor : %s", caps.Vendor.c_str())

	}

	void Application::OnEvent(Event& e)
	{
		SR_CORE_TRACE("{0}", e);

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(SR_BIND_EVENT_FUNC(Application::OnWindowClose));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Runing = false;
		return true;
	}

	void Application::Run()
	{	
		while (m_Runing)
		{
			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			RenderCommand::SetClearColor({0.1f, 0.1f, 0.1f, 1});
			RenderCommand::Clear();

			
			//Renderer::BeginScene();


			Renderer::EndScene();


			for (Layer* layer : m_LayerStack)  
			{
				layer->OnUpdate(timestep);
			}

			m_GuiLayer->Begin();
			for(Layer* layer : m_LayerStack)
				layer->OnGuiRender();
			m_GuiLayer->End();

			m_Window->OnUpdate();
		}
	}  
}
