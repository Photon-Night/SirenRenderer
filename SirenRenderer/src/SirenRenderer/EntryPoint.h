#pragma once
#ifdef SR_PLATFORM_WINDOWS
extern SirenRenderer::Application* SirenRenderer::CreateApplication();

int main(int argc, char** argv)
{
	
	SirenRenderer::Log::Init();
	SR_CORE_WARN("Log Init");
	SR_INFO("Hello");
	
	auto app = SirenRenderer::CreateApplication();
	app->Run();
	delete app;
}

#endif