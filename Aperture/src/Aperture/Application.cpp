#include "Application.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
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
		AE_TRACE(event);
		
		const int MOUSEBUTTON = 10;
		MouseButtonPressed event1(MOUSEBUTTON, true);
		AE_TRACE(event1);

		MouseButtonReleased event2(MOUSEBUTTON);
		AE_TRACE(event2);

		MouseMoved event3(1.1f, 2.2f);
		AE_TRACE(event3);

		MouseScrolled event4(20.0f);
		AE_TRACE(event4); 

		while (true);
	}
}
