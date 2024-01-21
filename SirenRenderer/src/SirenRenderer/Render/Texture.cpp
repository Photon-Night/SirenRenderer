#include "srpch.h"
#include "Texture.h"
#include "SirenRenderer/Render/RendererAPI.h"
#include "SirenRenderer/Render/Renderer.h"
#include "SirenRenderer/Platform/OpenGL/OpenGLTexture2D.h"

namespace SirenRenderer
{
	Ref<Texture2D> Texture2D::Create(const TextureSpecification& specification)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(specification);
		}

		SR_CORE_ASSERTS(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    SR_CORE_ASSERTS(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
		}

		SR_CORE_ASSERTS(false, "Unknown RendererAPI!");
		return nullptr;
	}
}
