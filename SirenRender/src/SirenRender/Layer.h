#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace SirenRender
{
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;
		virtual void OnDetach() {}
		virtual void OnAttach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const {return m_DebugName;}
	protected:
		std::string m_DebugName;
	};
}


