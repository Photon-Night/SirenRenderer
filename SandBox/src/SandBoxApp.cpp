#include <SirenRender.h>

class SandBox : public SirenRender::Application
{
	public:
		SandBox()
		{
			PushOverlay(new SirenRender::GUILayer());

		}

		~SandBox()
		{

		}
};

SirenRender::Application* SirenRender::CreateApplication()
{
	return new SandBox();
}
