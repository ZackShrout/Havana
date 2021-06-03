#pragma once

#ifdef HV_PLATFORM_WINDOWS

extern Havana::Application* Havana::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Havana::CreateApplication();
	app->Run();
	delete app;
}

#endif
