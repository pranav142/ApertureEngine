#pragma once

#include "Event.h"

namespace Aperture
{
	class AE_API MouseButtonEvent: public Event
	{
	public: 

		int GetButton()
		{
			return m_button; 
		}

		virtual int GetCategoryFlags() const override
		{
			return EventCategory::EventCategoryInput | EventCategoryMouse | EventCategoryMouseButton;
		}

	protected: 
		MouseButtonEvent(int button)
			:m_button(button)
		{}
		
		int m_button;
	};

	class AE_API MouseButtonPressed: public MouseButtonEvent
	{
	public:
		
		MouseButtonPressed(int button, bool hold)
			:MouseButtonEvent(button),
			m_hold(hold)
		{}

		EventType GetEventType() const override
		{
			return EventType::MouseButtonPressed;
		}

		std::string ToString() const override
		{
			std::stringstream ss; 
			ss << "Mouse Button Clicked: " << m_button;
			ss << " (Hold = " << m_hold << ")";
			ss << ", Occured: " << m_Timestamp;
			return ss.str();
		}

		bool isHold()
		{
			return m_hold;
		}

	protected:
		int m_hold;
	};

	class AE_API MouseButtonReleased : public MouseButtonEvent	
	{
	public: 

		MouseButtonReleased(int button)
			:MouseButtonEvent(button)
		{}

		EventType GetEventType() const override
		{
			return EventType::MouseButtonReleased;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released: " << m_button;
			ss << ", Occured: " << m_Timestamp;
			return ss.str();
		}
	};

	class AE_API MouseMoved: public Event
	{
	public:
		MouseMoved(float x, float y)
			:m_x(x),
			m_y(y)
		{}
		
		float GetX()
		{
			return m_x;
		}

		float GetY()
		{
			return m_y;
		}

		EventType GetEventType() const override
		{
			return EventType::MouseMoved;
		}

		int GetCategoryFlags() const override
		{
			return EventCategory::EventCategoryApplication | EventCategoryMouse; 
		}

		std::string ToString() const override
		{
			std::stringstream ss; 
			ss << "Mouse Moved: x=" << m_x << " y=" << m_y; 
			ss << ", Occured: " << m_Timestamp;
			return ss.str();
		}

	private:
		float m_x; 
		float m_y;
	};

	class AE_API MouseScrolled : public Event
	{
	public:
		MouseScrolled(float scroll)
			:m_scroll(scroll)
		{}

		float getScroll()
		{
			return m_scroll;
		}

		EventType GetEventType() const override
		{
			return EventType::MouseScrolled;
		}

		int GetCategoryFlags() const override
		{
			return EventCategory::EventCategoryApplication | EventCategoryMouse;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse scrolled: " << m_scroll; 
			ss << ", Occured: " << m_Timestamp;
			return ss.str();
		}

	private:
		float m_scroll;
	};
}
