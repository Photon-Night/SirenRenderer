#include "srpch.h"
#include "glad/glad.h"
#include "OpenGLVertexArray.h"

namespace SirenRenderer
{
	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
		case SirenRenderer::ShaderDataType::Float:		return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Float2:		return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Float3:		return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Float4:		return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Mat3:			return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Mat4:			return GL_FLOAT;
		case SirenRenderer::ShaderDataType::Int:			return GL_INT;
		case SirenRenderer::ShaderDataType::Int2:			return GL_INT;
		case SirenRenderer::ShaderDataType::Int3:			return GL_INT;
		case SirenRenderer::ShaderDataType::Int4:			return GL_INT;
		case SirenRenderer::ShaderDataType::Bool:			return GL_BOOL;
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

	void OpenGLVertexArray::AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer)
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

	void OpenGLVertexArray::SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RenderID);
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}      
}