#pragma once
#include "VertexArray.h"
#include "SirenRenderer/Render/RendererAPI.h"
#include "SirenRenderer/Render/Shader.h"
#include "SirenRenderer/Render/OrthographicCamera.h"
namespace SirenRenderer
{
	class Renderer
	{
	public:
		static void Init();
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		static void Submit(const Ref<VertexArray>& vertexArray, const Ref<Shader>& shader);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); };

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> m_SceneData;
	};
}