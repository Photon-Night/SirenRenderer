#pragma once
#include "SirenRender/Layer.h"
#include "SirenRender/Events/MouseEvent.h"
#include "SirenRender/Events/KeyEvent.h"
#include "SirenRender/Events/ApplicationEvent.h"

namespace SirenRender
{
	class SIREN_API GUILayer : public Layer
	{
	public:
		GUILayer();
		~GUILayer();

		void OnDetach();
		void OnAttach();
		void OnUpdate();
		void OnEvent(Event& event);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& event);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);
		bool OnMouseMovedEvent(MouseMovedEvent& event);
		bool OnMouseScrolledEvent(MouseScrolledEvent& event);
		bool OnKeyPressedEvent(KeyPressedEvent& evnet);
		bool OnKeyReleasedEvent(KeyReleasedEvent& evnet);
		bool OnWindowResizeEvent(WindowResizeEvent& event);
	private:
		float m_Time = 0.0f;
	};
}


