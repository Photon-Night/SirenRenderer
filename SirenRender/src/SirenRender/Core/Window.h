#pragma once
#include "SirenRender/Events/Event.h"
#include <sstream>


namespace SirenRender
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string title = "Siren Render",
			uint32_t w = 1600,
			uint32_t h = 900)
			: Title(title), Width(w), Height(h)
		{
		}
	};

	class SIREN_API Window
	{
	public:
		using EventCallBack = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallBack(const EventCallBack& callback) = 0;
		virtual void SetVSync(bool enable) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};
}