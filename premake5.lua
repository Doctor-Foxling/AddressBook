workspace "AddressBook"
	architecture "x64"
	targetdir "build"

	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	} 

	platforms {
		"win64",
		"win32",
		"linux64",
		"linux86",
		"macos"
	}
	
	flags
	
	{
		"MultiProcessorCompile"
	}

	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}


project "AddressBook"
	location "AddressBook"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "AddressBook/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
	}


	filter "system:windows"
		systemversion "latest"

	filter "platforms:win64"

	filter "platforms:linux64"

	filter "platforms:win32"

	filter "platforms:linux86"

	filter "platforms:macos"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"