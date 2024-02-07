#pragma once
#include <glm/glm.hpp>
#include "SirenRenderer/Render/RendererAPI.h"

namespace SirenRenderer
{
	class FrameBuffer
	{
		enum class FramebufferFormat
		{
			None = 0,
			RGBA8 = 1,
			RGBA16F = 2,
		};

		struct FramebufferSpecification
		{
			uint32_t Width = 1280;
			uint32_t Height = 720;
			glm::vec4 ClearColor;
			FramebufferFormat Format;
			uint32_t Samples = 1; // multisampling

			// SwapChainTarget = screen buffer (i.e. no framebuffer)
			bool SwapChainTarget = false;
		};

		class Framebuffer
		{
		public:
			virtual ~Framebuffer() {};
			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void Resize(uint32_t width, uint32_t height, bool forceRecreate = false) = 0;

			virtual void BindTexture(uint32_t slot = 0) const = 0;
			
			virtual RendererID GetRendererID() const = 0;
			virtual RendererID GetColorAttachmentRendererID() const = 0;
			virtual RendererID GetDepthAttachmentRendererID() const = 0;

			virtual const FramebufferSpecification& GetSpecification() const = 0;

			static Ref<Framebuffer> Create(const FramebufferSpecification& spec);
		};

	};
}


