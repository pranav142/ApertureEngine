#pragma once


namespace Aperture
{	

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	class Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;
	};

	class EventDispatcher
	{
	public: 

		EventDispatcher(Event event)
			:m_event(event)
		{}

		
	private:
		Event m_event;
	};
}
