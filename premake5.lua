workspace "SirenRenderer"
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
IncludeDir["glfw"] = "SirenRenderer/vendor/glfw/include"
IncludeDir["glad"] = "SirenRenderer/vendor/glad/include"
IncludeDir["imgui"] = "SirenRenderer/vendor/imgui"
IncludeDir["glm"] = "SirenRenderer/vendor/glm"
IncludeDir["stb_image"] = "SirenRenderer/vendor/stb_image"

include "SirenRenderer/vendor/glad"
include "SirenRenderer/vendor/ImGui"

project "SirenRenderer"
	location "SirenRenderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "SirenRenderer/src/srpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"{prj.name}/vendor/glm/glm/**.hpp",
		"{prj.name}/vendor/glm/glm/**.inl",
		"{prj.name}/vendor/stb_image/**.h",
		"{prj.name}/vendor/stb_image/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
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
		"SirenRenderer/vendor/spdlog/include",
		"SirenRenderer/src",
		"SirenRenderer/vendor",
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
			"SirenRenderer"
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