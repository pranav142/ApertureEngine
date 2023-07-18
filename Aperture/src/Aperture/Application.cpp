
#include "aepch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Log.h"
#include "Components/component.h"
#include "Entities/Entity.h"
#include "SFML/Graphics.hpp"

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
		
		PositionComponent position(20, 5); 
		AE_TRACE(position);

		Entity player; 
		player.cPosition = std::make_shared<PositionComponent>(10, 5);
		player.cName = std::make_shared<NameComponent>(); 

		AE_TRACE(player); 
		AE_TRACE(player.cName->name);
		
	}
}
