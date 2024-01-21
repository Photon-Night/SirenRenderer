#include "srpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "SirenRenderer/Platform/OpenGL/OpenGLBuffer.h"
#include "SirenRenderer/Core/Assert.h"

namespace SirenRenderer
{
	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::OpenGL:		return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		SR_CORE_ASSERTS(false, "[VectorBuffer] <Create> Unknown RendererAPI");

		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::OpenGL:			return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		SR_CORE_ASSERTS(false, "[IndexBuffer] <Create> Unknown RendererAPI");

		return nullptr;
	}
}
