#include "srpch.h"
#include "glad/glad.h"
#include "Application.h"
#include "glfw3.h"
#include "Render/RenderCommand.h"
#include "Render/Renderer.h"

namespace SirenRenderer
{

	Application* Application::s_Instance = nullptr;

	
	
	Application::Application()
	{  
		SR_CORE_ASSERTS(!s_Instance, "Application already exists");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(SR_BIND_EVENT_FUNC(Application::OnEvent));

		m_GuiLayer = new GUILayer();
		PushOverlay(m_GuiLayer);
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
