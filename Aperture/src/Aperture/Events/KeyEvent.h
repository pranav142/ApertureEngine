#pragma once

#include <string>
#include "Event.h"
#include <sstream>

namespace Aperture
{
	class AE_API KeyEvent : public Event
	{
	public:
		KeyEvent(const int& KeyCode)
			:m_KeyCode(KeyCode){}
		
		int GetKeyCode() const
		{
			return m_KeyCode;
		}

		virtual int GetCategoryFlags() const override 
		{
			return EventCategory::EventCategoryInput | EventCategoryKeyboard;
		}

	protected: 
		int m_KeyCode;
	};

	class AE_API KeyPressEvent : public KeyEvent
	{
	public: 
		KeyPressEvent(const int KeyCode, const bool isRepeat, const int shiftModifier = false, const int ctrlModifier = false, const int altModifier = false)
			:KeyEvent(KeyCode),
			m_isRepeat(isRepeat),
			m_shiftModifier(shiftModifier),
			m_ctrlModifier(ctrlModifier),
			m_altModifier(altModifier)
		{}

		bool GetIsRepeat() const
		{	
			return m_isRepeat;
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed Event - Key Code: " << m_KeyCode;
			ss << " (is repeat = " << m_isRepeat;
			ss << ", shift = " << m_shiftModifier;
			ss << ", ctrl = " << m_ctrlModifier;
			ss << ", alt = " << m_altModifier << ")";
			ss << ", Event Occured: " << m_Timestamp;
			return ss.str();
		}
		
		virtual EventType GetEventType() const override
		{
			return EventType::KeyPressed;
		}

	protected: 
		bool m_isRepeat;
		bool m_shiftModifier; 
		bool m_ctrlModifier; 
		bool m_altModifier;
	};

	class AE_API KeyReleaseEvent: public KeyEvent
	{
	public:
		KeyReleaseEvent(const int KeyCode)
			:KeyEvent(KeyCode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released Event - Key Code: " << m_KeyCode;
			ss << ", Event Occured: " << m_Timestamp;
			return ss.str();
		}

		virtual EventType GetEventType() const override
		{
			return EventType::KeyReleased;
		}
	};
}
