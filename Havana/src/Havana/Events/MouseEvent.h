#pragma once

#include "Event.h"

#include <sstream>

namespace Havana
{
	class HAVANA_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : mouseX(x), mouseY(y) { }
		inline float GetX() const { return mouseX; }
		inline float GetY() const { return mouseY; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoved Event: " << mouseX << ", " << mouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mouseX, mouseY;
	};

	class HAVANA_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset) : xOffset(xOffset), yOffset(yOffset) { }
		inline float GetXOffset() const { return xOffset; }
		inline float GetYOffset() const { return yOffset; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolled Event: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float xOffset, yOffset;
	};

	class HAVANA_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : button(button) { }
		int button;
	};

	class HAVANA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) { }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed Event: " << button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class HAVANA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) { }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressed Event: " << button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}