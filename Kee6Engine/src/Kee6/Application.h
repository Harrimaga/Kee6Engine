#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Kee6
{

	class KEE6_API Application
	{
		public:
			Application();
			virtual ~Application();

			void Run();
	};

	Application* CreateApplication();

}


