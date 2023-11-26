#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Core/Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace SirenRender
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
	private:
		std::unique_ptr<Window> m_Window; 
		bool m_Runing = true;

		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}


