#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Core/Window.h"
#include "Events/ApplicationEvent.h"
#include "SirenRenderer/Core/Assert.h"
#include "LayerStack.h"
#include "SirenRenderer/GUI/GUILayer.h"
#include "SirenRenderer/Core/Timestep.h"

namespace SirenRenderer
{
	struct ApplicationProps
	{
		std::string Name;
		uint32_t WindowWidth, WindowHeight;
	};


	class SIREN_API Application
	{
	public:
		Application(const ApplicationProps& props = {"Siren Renderer", 1280, 70});
		~Application();

		void Run();

		virtual void OnInit();
		virtual void OnShutdown();
		virtual void OnUpdate(Timestep ts);
		virtual void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void RenderGui();

		std::string OpenFile(const std::string& filter) const;

		inline static Application& GetInstance() {return *s_Instance;}
		inline Window& GetWindow() {return *m_Window;}
		float GetTime() const;

	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		Scope<Window> m_Window; 
		LayerStack m_LayerStack;
		GUILayer* m_GuiLayer;
		Timestep m_Timestep;
		bool m_Runing = true;
		bool m_Minimized = false;
		float m_LastFrameTime = 0.0f;
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


