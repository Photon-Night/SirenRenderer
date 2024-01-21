#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "SirenRenderer/Core/Timestep.h"

namespace SirenRenderer
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;
		virtual void OnDetach() {}
		virtual void OnAttach() {}
		virtual void OnGuiRender() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const {return m_DebugName;}
	protected:
		std::string m_DebugName;
	};
}


