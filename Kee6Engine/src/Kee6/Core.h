#pragma once

#ifdef K6_PLATFORM_WINDOWS
	#ifdef K6_BUILD_DLL
		#define KEE6_API __declspec(dllexport)
	#else
		#define KEE6_API __declspec(dllimport)
	#endif
#else
	#error Kee6Engine only supports Windows.
#endif

#define BIT(x) = (1 << x)