workspace "SirenRender"
	architecture "x64"

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

include "SirenRender/vendor/glad"
include "SirenRender/vendor/ImGui"

project "SirenRender"
	location "SirenRender"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "srpch.h"
	pchsource "SirenRender/src/srpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{prj.name}/vendor/glm"
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
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		

		defines
		{
			"SR_PLATFORM_WINDOWS",
			"SR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}


	filter "configurations:Debug"
		defines "SR_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		
		 
	filter "configurations:Release"
		defines "SR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		buildoptions "/MD"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

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
		"SirenRender/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

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
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SR_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "SR_DIST"
		buildoptions "/MD"
		optimize "On"