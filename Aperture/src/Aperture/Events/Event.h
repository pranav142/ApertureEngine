#pragma once
#include "../Core.h"
#include <functional>
#include <string>
#include <chrono>
#include "../Log.h"

namespace Aperture
{	
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class AE_API Event
	{
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const = 0;

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		std::string GetTimestamp() const
		{	
			return m_Timestamp;
		}

	protected:
		std::string m_Timestamp;

		Event()
			: m_Timestamp(GetCurrentTimestampAsString())
		{
		}

		static std::string GetCurrentTimestampAsString()
		{
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			std::string timestamp = std::ctime(&time);
			timestamp.pop_back();
			return timestamp;
		}
	};

	class AE_API EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		// F will be deduced by the compiler
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if (m_Event.GetEventType() == T::GetEventType())
			{
				func(m_Event);
				m_event.Handled = True;
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
