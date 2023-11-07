workspace "SirenRender"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SirenRender"
	location "SirenRender"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputDir .. "/Sandbox/\"")
		}


	filter "configurations:Debug"
		defines "SR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SirenRender/vendor/spdlog/include",
		"SirenRender/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines
		{
			"SR_PLATFORM_WINDOWS"
		}

		links
		{
			"SirenRender"
		}


	filter "configurations:Debug"
		defines "SR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		optimize "On"