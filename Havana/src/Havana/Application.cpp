#include "Application.h"

#include "Havana/Events/ApplicationEvent.h"
#include "Havana/Log.h"

namespace Havana
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		HV_INFO(e);
		
		while (true);
	}
}
