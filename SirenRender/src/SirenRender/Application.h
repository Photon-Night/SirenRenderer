#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Core/Window.h"
#include "Events/ApplicationEvent.h"

namespace SirenRender
{
	class SIREN_API Application
	{
	public:
		Application();
		~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window; 
		bool m_Runing = true;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}


