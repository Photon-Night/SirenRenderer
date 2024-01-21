#include "srpch.h"
#include "VertexArray.h"
#include "SirenRenderer/Render/Renderer.h"
#include <SirenRenderer/Platform/OpenGL/OpenGLVertexArray.h>

namespace SirenRenderer
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported");
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLVertexArray>();
			default:
				break;
		}

		SR_CORE_ASSERTS(false, "Unknown RenderAPI");
		return nullptr;
	}
}
