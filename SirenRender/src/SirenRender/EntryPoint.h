#pragma once
#ifdef SR_PLATFORM_WINDOWS
extern SirenRender::Application* SirenRender::CreateApplication();

int main(int argc, char** argv)
{
	
	SirenRender::Log::Init();
	SR_CORE_WARN("Log Init");
	SR_INFO("Hello");
	
	std::cout << "Render Start" << std::endl;
	auto app = SirenRender::CreateApplication();
	app->Run();
	delete app;
}

#endif