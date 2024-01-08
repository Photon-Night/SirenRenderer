#pragma once
#include <string>
namespace SirenRender
{
	class Shader
	{
	public :
		Shader(const std::string& vertPath, const std::string& fragPath);
		~Shader();

		void Bind() const;
		void UnBind() const;

	private:
		void checkCompileErrors(unsigned int shader, std::string type);

	private:
		uint32_t m_RendererID;
	};
}


