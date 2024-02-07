#pragma once
#include "glm/glm.hpp"
#include "VertexArray.h"

namespace SirenRenderer
{
	using RendererID = uint32_t;
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1,
		};

		enum class PrimitiveType
		{
			None = 0,
			Triangles,
			Lines
		};

		struct RenderAPICapabilities
		{
			std::string Vendor;
			std::string Renderer;
			std::string Version;

			int MaxSample = 0;
			float MaxAnusotropy = 0.0f;
			int MaxTextureUnits = 0;
		};

	public:
		static void Init();
		static void Shutdown();

		static void Clear(const glm::vec4& color);
		static void SetClearColor(const glm::vec4& color);
		//virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;

		static void DrawIndexed(uint32_t count, PrimitiveType type, bool depthTest = true);
		static void SetLineThickness(float thickness);
		//static void DrawLines(const Ref<VertexArray>& vertexArray, uint32_t vertexCount);

		//virtual void SetLineWidth(float width) = 0;

		static RenderAPICapabilities& GetCapabilities()
		{
			static RenderAPICapabilities capabilities;
			return capabilities;
		}

		static API GetAPI() { return s_API; }
		//static Scope<RendererAPI> Create();
	private:
		static void LoadRequireAssets();
	private:
		static API s_API;
	};
}


