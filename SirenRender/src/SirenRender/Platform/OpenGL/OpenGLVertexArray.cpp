#include "srpch.h"
#include "glad/glad.h"
#include "OpenGLVertexArray.h"

namespace SirenRender
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case SirenRender::ShaderDataType::Float:		return GL_FLOAT;
		case SirenRender::ShaderDataType::Float2:		return GL_FLOAT;
		case SirenRender::ShaderDataType::Float3:		return GL_FLOAT;
		case SirenRender::ShaderDataType::Float4:		return GL_FLOAT;
		case SirenRender::ShaderDataType::Mat3:			return GL_FLOAT;
		case SirenRender::ShaderDataType::Mat4:			return GL_FLOAT;
		case SirenRender::ShaderDataType::Int:			return GL_INT;
		case SirenRender::ShaderDataType::Int2:			return GL_INT;
		case SirenRender::ShaderDataType::Int3:			return GL_INT;
		case SirenRender::ShaderDataType::Int4:			return GL_INT;
		case SirenRender::ShaderDataType::Bool:			return GL_BOOL;
		default:
			break;
		}

		return GL_NONE;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RenderID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RenderID);
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RenderID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		glBindVertexArray(m_RenderID);
		vertexBuffer->Bind();

		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, 
				element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.type),
				element.normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(), 
				(const void*)element.offest);

			index ++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RenderID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}      
}