#include "srpch.h"
#include "RendererAPI.h"
#include "SirenRender/Platform/OpengL/OpenGLRendererAPI.h"
namespace SirenRender
{
	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	std::shared_ptr<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
			case SirenRender::RendererAPI::API::None:		SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported"); return nullptr;
			case SirenRender::RendererAPI::API::OpenGL:		return std::shared_ptr<OpenGLRendererAPI>(new OpenGLRendererAPI());
			default:
				break;
		}

		SR_CORE_ASSERTS(false, "Unkonwn RendererAPI");
		return nullptr;
	}
}
