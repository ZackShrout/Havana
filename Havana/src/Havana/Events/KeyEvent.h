#pragma once

#include "Event.h"

#include <sstream>

namespace Havana
{
	class HAVANA_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return keyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int keyCode) : keyCode(keyCode) { }
		int keyCode;
	};

	class HAVANA_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), repeatCount(repeatCount) { }
		inline int GetRepeatCount() const { return repeatCount; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int repeatCount;
	};

	class HAVANA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) { }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << keyCode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}