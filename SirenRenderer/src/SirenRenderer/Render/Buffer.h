#pragma once
#include <SirenRenderer/Core/Assert.h>

namespace SirenRenderer
{
	enum class ShaderDataType
	{
		None = 0,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
		Int, Int2, Int3, Int4,
		Bool,
	};

	static uint32_t GetShaderTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case SirenRenderer::ShaderDataType::None:			return 4;
			break;
		case SirenRenderer::ShaderDataType::Float:		return 4;
			break;
		case SirenRenderer::ShaderDataType::Float2:		return 4 * 2;
			break;
		case SirenRenderer::ShaderDataType::Float3:		return 4 * 3;
			break;
		case SirenRenderer::ShaderDataType::Float4:		return 4 * 4;
			break;
		case SirenRenderer::ShaderDataType::Mat3:			return 4 * 3 * 3;
			break;
		case SirenRenderer::ShaderDataType::Mat4:			return 4 * 4 * 4;
			break;
		case SirenRenderer::ShaderDataType::Int:			return 4;
			break;
		case SirenRenderer::ShaderDataType::Int2:			return 4 * 2;
			break;
		case SirenRenderer::ShaderDataType::Int3:			return 4 * 3;
			break;
		case SirenRenderer::ShaderDataType::Int4:			return 4 * 4;
			break;
		case SirenRenderer::ShaderDataType::Bool:			return 1;
			break;
		default:
			break;
		}


		SR_CORE_ASSERTS(false, "[StaticFunction] <GetShaderTypeSize> Unknown ShaderType");

		return 0;
	}

	struct BufferElement
	{
	public:
		std::string name;
		ShaderDataType type;
		uint32_t size;
		uint32_t offest;
		bool normalized;

		BufferElement(ShaderDataType type, const std::string name, uint32_t size = 0, uint32_t offest = 0, bool normalized = false)
			: name(name), type(type), size(size), offest(offest), normalized(normalized)
		{

		}


		uint32_t GetComponentCount() const
		{
			switch (type)
			{
			case SirenRenderer::ShaderDataType::None:			return 0;
				break;
			case SirenRenderer::ShaderDataType::Float:		return 1;
				break;
			case SirenRenderer::ShaderDataType::Float2:		return 2;
				break;
			case SirenRenderer::ShaderDataType::Float3:		return 3;
				break;
			case SirenRenderer::ShaderDataType::Float4:		return 4;
				break;
			case SirenRenderer::ShaderDataType::Mat3:			return 3 * 3;
				break;
			case SirenRenderer::ShaderDataType::Mat4:			return 4 * 4;
				break;
			case SirenRenderer::ShaderDataType::Int:			return 1;
				break;
			case SirenRenderer::ShaderDataType::Int2:			return 2;
				break;
			case SirenRenderer::ShaderDataType::Int3:			return 3;
				break;
			case SirenRenderer::ShaderDataType::Int4:			return 4;
				break;
			case SirenRenderer::ShaderDataType::Bool:			return 1;
				break;
			default:
				break;
			}

			return 0;
		}
	};

	class BufferLayout
	{
	public:
		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		inline const uint32_t GetStride() const { return m_Stride; }
		BufferLayout() = default;

		BufferLayout(const std::initializer_list<BufferElement>& element)
			: m_Elements(element)
		{
			CalculateOffestAndStride();
		}

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }
	private:
		void CalculateOffestAndStride()
		{
			uint32_t offest = 0;
			m_Stride = 0;
			for (auto element : m_Elements)
			{
				element.offest = offest;
				offest += element.size;
				m_Stride += element.size;
			}
		}
	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const= 0;
		virtual void Unbind() const= 0;

		virtual void SetLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& GetLayout() const = 0;

		static Ref<VertexBuffer> Create(float* vertices, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer(){}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static Ref<IndexBuffer> Create(uint32_t* indices, uint32_t count);
	};
}


