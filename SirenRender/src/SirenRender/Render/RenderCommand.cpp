#include "srpch.h"
#include "RenderCommand.h"

namespace SirenRender
{
	std::shared_ptr<RendererAPI>& RenderCommand::s_RendererAPI = RendererAPI::Create();
}