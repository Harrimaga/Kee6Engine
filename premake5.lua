workspace "Kee6Engine"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Kee6Engine"
	location "Kee6Engine"
	kind "SharedLib"
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
		"Kee6Engine/vendor/spdlog/include",
		"Kee6Engine/src"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"K6_PLATFORM_WINDOWS",
			"K6_BUILD_DLL"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	filter "configurations:Debug"
		defines "K6_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "K6_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "K6_DIST"
		optimize "On"

project "Game"
	location "Game"
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
		"Kee6Engine/vendor/spdlog/include",
		"Kee6Engine/src"
	}

	links
	{
		"Kee6Engine"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"K6_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "K6_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "K6_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "K6_DIST"
		optimize "On"