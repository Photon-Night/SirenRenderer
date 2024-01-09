#include "srpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "SirenRender/Platform/OpenGL/OpenGLBuffer.h"
#include "SirenRender/Core/Assert.h"

namespace SirenRender
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::OpenGL:		return new OpenGLVertexBuffer(vertices, size);
		}

		SR_CORE_ASSERTS(false, "Unknow RendererAPI");

		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::OpenGL:		return new OpenGLIndexBuffer(indices, size);
		}

		SR_CORE_ASSERTS(false, "Unknow RendererAPI");

		return nullptr;
	}
}
