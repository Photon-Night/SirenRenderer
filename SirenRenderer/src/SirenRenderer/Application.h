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
	class SIREN_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline static Application& GetInstance() {return *s_Instance;}
		inline Window& GetWindow() {return *m_Window;}
	private:
		Scope<Window> m_Window; 
		GUILayer* m_GuiLayer;
		bool m_Runing = true;

		bool OnWindowClose(WindowCloseEvent& e);
	private:
		Timestep m_Timestep;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


