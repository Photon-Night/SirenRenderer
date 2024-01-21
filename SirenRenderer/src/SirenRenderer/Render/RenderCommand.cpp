#include "srpch.h"
#include "RenderCommand.h"

namespace SirenRenderer
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}