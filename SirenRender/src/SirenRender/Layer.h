#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace SirenRender
{
	class SIREN_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}

	};
}


