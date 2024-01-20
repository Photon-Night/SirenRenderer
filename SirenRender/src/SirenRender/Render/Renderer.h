#pragma once
#include "VertexArray.h"
#include "SirenRender/Render/RendererAPI.h"
namespace SirenRender
{
	class Renderer
	{
	public:
		static void BeginScene();
		static void EndScene();
		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };
	};
}