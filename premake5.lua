workspace "SirenRender"
	architecture "x64"
	startproject "SandBox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glfw"] = "SirenRender/vendor/glfw/include"
IncludeDir["glad"] = "SirenRender/vendor/glad/include"
IncludeDir["imgui"] = "SirenRender/vendor/imgui"
IncludeDir["glm"] = "SirenRender/vendor/glm"

include "SirenRender/vendor/glad"
include "SirenRender/vendor/ImGui"

project "SirenRender"
	location "SirenRender"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "SirenRender/src/srpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"{prj.name}/vendor/glm/glm/**.hpp",
		"{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	libdirs
	{
		"%{prj.name}/vendor/glfw/lib"
	}

	links
	{
		"glfw3_mt.lib",
		"ImGui",
		"glad",
		"opengl32"
	}

	

	filter "system:windows"
		systemversion "latest"
		

		defines
		{
			"IMGUI_API=__declspec(dllexport)",
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		--postbuildcommands
		--{
		--	("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		--}


	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "on"
		
		 
	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "on"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SirenRender/vendor/spdlog/include",
		"SirenRender/src",
		"SirenRender/vendor",
		"%{IncludeDir.glm}"
	}

	filter "system:windows"
		
		systemversion "latest"

		defines
		{
			"IMGUI_API=__declspec(dllimport)",
			"SR_PLATFORM_WINDOWS"
		}

		links
		{
			"SirenRender"
		}


	filter "configurations:Debug"
		defines "SR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SR_DIST"
		runtime "Release"
		optimize "on"