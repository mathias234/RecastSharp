--
-- premake5 file to build RecastDemo
-- http://premake.github.io/
--

local action = _ACTION or ""
local todir = "Build/" .. action

solution "recastwrapper"
	configurations { 
		"Debug",
		"Release"
	}

	location (todir)

	floatingpoint "Fast"
	symbols "On"
	exceptionhandling "Off"
	rtti "Off"
	flags { "FatalCompileWarnings" }

	-- debug configs
	configuration "Debug*"
		defines { "DEBUG" }
		targetdir ( todir .. "/lib/Debug" )
 
 	-- release configs
	configuration "Release*"
		defines { "NDEBUG" }
		optimize "On"
		targetdir ( todir .. "/lib/Release" )

	configuration "not windows"
		warnings "Extra"

	-- windows specific
	configuration "windows"
		platforms { "Win32", "Win64" }
		defines { "WIN32", "_WINDOWS", "_CRT_SECURE_NO_WARNINGS", "_HAS_EXCEPTIONS=0" }
		-- warnings "Extra" uses /W4 which is too aggressive for us, so use W3 instead.
		-- Disable:
		-- * C4351: new behavior for array initialization
		buildoptions { "/W3", "/wd4351" }

	configuration { "linux", "gmake2" }
		buildoptions { "-fPIC" }

	filter "platforms:Win32"
		architecture "x32"

	filter "platforms:Win64"
		architecture "x64"
project "Detour"
	language "C++"
	cppdialect "C++20"
	kind "StaticLib"
	includedirs { 
		"../RecastNav/Detour/Include" 
	}
	files { 
		"../RecastNav/Detour/Include/*.h", 
		"../RecastNav/Detour/Source/*.cpp" 
	}
	-- linux library cflags and libs
	configuration { "linux", "gmake2" }
		buildoptions { 
			"-Wno-class-memaccess",
			"-Wno-maybe-uninitialized"
		}
project "Recast"
	language "C++"
	cppdialect "C++20"
	kind "StaticLib"
	includedirs { 
		"../RecastNav/Recast/Include" 
	}
	files { 
		"../RecastNav/Recast/Include/*.h",
		"../RecastNav/Recast/Source/*.cpp" 
	}

project "RecastWrapper"
	language "C++"
	cppdialect "C++20"
	kind "SharedLib"
	includedirs {
		"Include",
		"../RecastNav/Recast/Include",
		"../RecastNav/Detour/Include"
	}
	files {
		"Include/*.h",
		"Source/*.cpp",
	}

	-- project dependencies
	links { 
		"Detour",
		"Recast"
	}

	filter "system:Linux"
		targetname "RecastWrapper"
		targetdir ( todir .. "/out/Release" )

	filter "platforms:Win32" 
		targetname "RecastWrapper"
		targetdir ( todir .. "/out/x86/Release" )

	filter "platforms:Win64"
		targetname "RecastWrapper"
		targetdir ( todir .. "/out/x64/Release" )

	filter "system:Macosx"
		targetname "RecastWrapper"
		targetdir ( todir .. "/out/Release" )

