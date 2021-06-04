#pragma once

#ifdef HV_PLATFORM_WINDOWS

extern Havana::Application* Havana::CreateApplication();

int main(int argc, char** argv)
{
	Havana::Log::Init();
	HV_CORE_WARN("Initialized Log!");
	int a = 5;
	HV_INFO("{0} Bunnies!", a);
	
	auto app = Havana::CreateApplication();
	app->Run();
	delete app;
}

#endif
