#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Core/Window.h"
#include "Events/ApplicationEvent.h"
#include "SirenRender/Core/Assert.h"
#include "LayerStack.h"
#include "SirenRender/GUI/GUILayer.h"

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

		inline static Application& GetInstance() {return *s_Instance;}
		inline Window& GetWindow() {return *m_Window;}
	private:
		std::unique_ptr<Window> m_Window; 
		GUILayer* m_GuiLayer;
		bool m_Runing = true;

		bool OnWindowClose(WindowCloseEvent& e);

		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}


