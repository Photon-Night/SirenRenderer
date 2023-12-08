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

		virtual void OnDetach() override;
		virtual void OnAttach() override;
		virtual void OnGuiRender() override; 

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}


