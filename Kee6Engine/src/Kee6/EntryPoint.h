#pragma once
#include "Application.h"

#ifdef K6_PLATFORM_WINDOWS

extern Kee6::Application* Kee6::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kee6::CreateApplication();
	app->Run();
	delete app;
}

#endif