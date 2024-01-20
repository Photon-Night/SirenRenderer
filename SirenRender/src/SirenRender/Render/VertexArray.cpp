#include "srpch.h"
#include "VertexArray.h"
#include "SirenRender/Render/Renderer.h"
#include <SirenRender/Platform/OpenGL/OpenGLVertexArray.h>

namespace SirenRender
{
	std::shared_ptr<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported");
			case RendererAPI::API::OpenGL:	return std::shared_ptr<OpenGLVertexArray>();
			default:
				break;
		}

		SR_CORE_ASSERTS(false, "Unknown RenderAPI");
		return nullptr;
	}
}
