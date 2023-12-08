#include <SirenRender.h>

class SandBox : public SirenRender::Application
{
	public:
		SandBox()
		{
			

		}

		~SandBox()
		{

		}
};

SirenRender::Application* SirenRender::CreateApplication()
{
	return new SandBox();
}
