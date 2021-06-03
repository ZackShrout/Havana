#pragma once
#include "Core.h"

namespace Havana
{
	class HAVANA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined in Client
	Application* CreateApplication();
}


