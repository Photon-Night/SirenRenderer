#pragma once
#include "Core.h"
namespace SirenRender
{
	class SIREN_API Application
	{
		public:
			Application();
			~Application();

			void Run();
	};

	Application* CreateApplication();
}


