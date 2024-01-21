#pragma once
#include "SirenRenderer/Layer.h"
#include "SirenRenderer/Events/MouseEvent.h"
#include "SirenRenderer/Events/KeyEvent.h"
#include "SirenRenderer/Events/ApplicationEvent.h"


namespace SirenRenderer
{
	class SIREN_API GUILayer : public Layer
	{
	public:
		GUILayer();
		~GUILayer();

		virtual void OnDetach() override;
		virtual void OnAttach() override;
		virtual void OnGuiRender() override; 

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}


