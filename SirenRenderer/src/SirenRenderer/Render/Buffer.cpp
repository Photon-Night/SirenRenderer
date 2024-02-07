#include "srpch.h"
#include "Buffer.h"
#include "Renderer.h"
#include "SirenRenderer/Platform/OpenGL/OpenGLBuffer.h"
#include "SirenRenderer/Core/Assert.h"

namespace SirenRenderer
{
	Ref<VertexBuffer> VertexBuffer::Create(void* data, uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLVertexBuffer>(data, size, usage);
		}
		SR_CORE_ASSERTS(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<VertexBuffer> VertexBuffer::Create(uint32_t size, VertexBufferUsage usage)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLVertexBuffer>(size, usage);
		}
		SR_CORE_ASSERTS(false, "Unknown RendererAPI");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(void* data, uint32_t size)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None:    return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<OpenGLIndexBuffer>(data, size);
		}
		SR_CORE_ASSERTS(false, "Unknown RendererAPI");
		return nullptr;

	}
}
