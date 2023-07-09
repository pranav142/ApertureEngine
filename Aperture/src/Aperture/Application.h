#pragma once

#include "Core.h"

namespace Aperture 
{

	class AE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApplication();

}

