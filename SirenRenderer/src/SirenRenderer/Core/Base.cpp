#include "srpch.h"
#include "Base.h"
#include "SirenRenderer/Log.h"

#define SR_BUILD_ID "v0.1a"

namespace SirenRenderer
{
	void InitializeCore()
	{
		SirenRenderer::Log::Init();

		SR_CORE_TRACE("Siren Renderer {}", SR_BUILD_ID);
		SR_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		SR_CORE_TRACE("Shutting down ...");
	}
}
