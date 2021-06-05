#pragma once

#ifdef HV_PLATFORM_WINDOWS
	#ifdef HV_BUILD_DLL
		#define HAVANA_API __declspec(dllexport)
	#else
		#define HAVANA_API __declspec(dllimport)
	#endif
#else
	#error Havana only supports Windows!
#endif

#define BIT(x) (1 << x)
