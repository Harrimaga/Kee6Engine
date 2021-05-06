#include "Application.h"

#include <Kee6/Events/ApplicationEvent.h>
#include "Kee6/Logger.h"

namespace Kee6
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
		K6_TRACE(e);
		while (true);
	}
}
