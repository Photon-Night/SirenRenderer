#include "srpch.h"
#include "RendererAPI.h"
#include "SirenRenderer/Platform/OpengL/OpenGLRendererAPI.h"
namespace SirenRenderer
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case SirenRenderer::RendererAPI::API::None:		SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported"); return nullptr;
			case SirenRenderer::RendererAPI::API::OpenGL:		return CreateScope<OpenGLRendererAPI>();
			default:
				break;
		}

		SR_CORE_ASSERTS(false, "Unkonwn RendererAPI");
		return nullptr;
	}
}
