#include "srpch.h"
#include "WindowsWindow.h"
#include "SirenRender/Core/Assert.h"
#include "SirenRender/Events/KeyEvent.h"
#include "SirenRender/Events/MouseEvent.h"
#include "SirenRender/Events/ApplicationEvent.h"

#include "glad/glad.h"

namespace SirenRender
{
	static bool  s_GLFWInitalized = false;

	static void GLFWErrorCallback(int error, const char* des)
	{
		SR_CORE_ERROR("GLFW Error ({0}): {1}" , error, des);
	}

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		m_Data.Title = props.Title;

		SR_CORE_INFO("Creating Window {0} {1} {2}", props.Title, props.Width, props.Height);

		if (!s_GLFWInitalized)
		{
			int success = glfwInit();
			SR_CORE_ASSERT(success, "Could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);
			s_GLFWInitalized = true;
		}


		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), NULL, NULL);
		if (m_Window)
		{
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, &m_Data);
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				SR_CORE_ERROR("Failed to initialize GLAD");
				return;
			}
			SetVSync(true);
			glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.Callback(event);
			});

			glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				
				WindowCloseEvent event;
				data.Callback(event);
			});

			glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
					case GLFW_PRESS:
					{
						KeyPressedEvent event(key, 0);
						data.Callback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleaseEvent event(key);
						data.Callback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(key, true);
						data.Callback(event);
						break;
					}
				}
			});

			glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypeEvent event(keycode);
				data.Callback(event);
			});

			glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
					WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

					switch (action)
					{
						case GLFW_PRESS:
						{
							MouseButtonPressedEvent event(button);
							data.Callback(event);
							break;
						}
						case GLFW_RELEASE:
						{
							MouseButtonReleasedEvent event(button);
							data.Callback(event);
							break;
						}
					}
			});

			glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrollEvent event((float)xPos, (float)yPos);
				data.Callback(event);
			});

			glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.Callback(event);
			});
		}
		else
		{
			SR_CORE_ERROR("Could not Create Window");
		}

		
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if(enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}