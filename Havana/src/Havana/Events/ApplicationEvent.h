#pragma once

#include "Event.h"

#include <sstream>

namespace Havana
{
	class HAVANA_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) { }
		inline unsigned int GetWidth() const { return width; }
		inline unsigned int GetHeight() const { return height; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResize Event: " << width << ", " << height;
			return ss.str();
		}
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int width, height;
	};

	class HAVANA_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() { }
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAVANA_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() { }
		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAVANA_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() { }
		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class HAVANA_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() { }
		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}