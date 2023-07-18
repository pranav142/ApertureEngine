#pragma once

#include "Event.h"

namespace Aperture
{
	class AE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent(){}

		virtual EventType GetEventType() const override
		{
			return EventType::WindowClose;
		}

		virtual int GetCategoryFlags() const override
		{
			return EventCategory::EventCategoryApplication;
		}
		
		std::string ToString() const override
		{
			std::stringstream ss; 
			ss << "Window Closed "; 
			ss << "Occured at: " << m_Timestamp;
			return ss.str();
		}
	};

	class AE_API WindowResizeEvent : public Event
	{
	public: 
		WindowResizeEvent(const int width, const int height) 
			:m_width(width), 
			m_height(height)
		{}
		
		virtual EventType GetEventType() const override
		{
			return EventType::WindowResize;
		}

		virtual int GetCategoryFlags() const override
		{
			return EventCategory::EventCategoryApplication;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resized Height: " << m_height << " width: " << m_width;
			ss << "Occured at Time: " << m_Timestamp; 
			return ss.str();
		}

		int get_width()
		{
			return m_width;
		}

		int get_height()
		{
			return m_height;
		}

	private: 
		int m_width, m_height;
	};
}
