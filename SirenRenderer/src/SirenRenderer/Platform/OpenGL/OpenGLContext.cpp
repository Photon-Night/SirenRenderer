#include "srpch.h"
#include "OpenGLContext.h"
#include "glad/glad.h"
#include <SirenRenderer/Core/Assert.h>
#include <GL/GL.h>

namespace SirenRenderer
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle )
	{
		SR_CORE_ASSERTS(windowHandle, "WindowHandle is null");
	}
	void OpenGLContext::Init()
	{

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwMakeContextCurrent(m_WindowHandle);
		
		bool status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SR_CORE_ASSERTS(status, "Failed to initialize Glad");
	}

	void OpenGLContext::SwapBuffers()
	{
		glBegin(GL_TRIANGLES);
		glEnd();

		glfwSwapBuffers(m_WindowHandle);
	}

}
