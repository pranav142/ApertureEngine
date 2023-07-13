#include "Application.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include <iostream>
#include "Log.h"

namespace Aperture
{
	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{	
		const int KEYCODE = 60;
		KeyPressEvent event(KEYCODE, false);
		AE_TRACE(event.ToString());
		while (true);
	}
}
