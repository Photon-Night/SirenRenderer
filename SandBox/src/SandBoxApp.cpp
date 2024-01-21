#include <SirenRenderer.h>

class SandBox : public SirenRenderer::Application
{
	public:
		SandBox()
		{
			

		}

		~SandBox()
		{

		}
};

SirenRenderer::Application* SirenRenderer::CreateApplication()
{
	return new SandBox();
}
