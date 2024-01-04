#pragma once
#include <string>
namespace SirenRender
{
	class Shader
	{
	public :
		Shader(const std::string vertSrc, const std::string fragSrc);
		~Shader();

		void Bind() const;
		void UnBind() const;

	private:
		uint32_t m_RendererID;
	};
}


