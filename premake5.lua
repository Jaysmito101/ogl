workspace "MySolution"
	architecture "x86"
	startproject "MyProject"

	configurations{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "ogl/vendor/glfw/include"
IncludeDir["Glad"] = "ogl/vendor/Glad/include"
IncludeDir["glm"] = "ogl/vendor/glm"
IncludeDir["ImGui"] = "ogl/vendor/imgui"
IncludeDir["ImPlot"] = "ogl/vendor/implot"
IncludeDir["ImGuiNodeEditor"] = "ogl/vendor/imgui-node-editor"
IncludeDir["ImColorTextEdit"] = "ogl/vendor/text-editor"
IncludeDir["Lua"] = "ogl/vendor/lua"
IncludeDir["MuParser"] = "ogl/vendor/muparser/include"

include "ogl/vendor/GLFW"
include "ogl/vendor/Glad"
include "ogl/vendor/imgui"
include "ogl/vendor/implot"
include "ogl/vendor/imgui-node-editor"
include "ogl/vendor/text-editor"
include "ogl/vendor/lua"
include "ogl/vendor/assimp"
include "ogl/vendor/muparser"

project "MyProject"
	location "MyProject"
	kind "ConsoleApp"
	cppdialect "C++17"
	language "C++"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .."/")
	objdir ("bin/intermediates/" .. outputdir .."/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.inl",
		"%{prj.name}/src/**.rc",
		"./ogl/ogl-core/**.c",
		"./ogl/ogl-core/**.cpp",
		"./ogl/ogl-core/**.h",
		"./ogl/ogl-core/**.hpp"
	}

	includedirs {
		"./ogl/vendor/assimp/include",
		"./ogl/ogl-core",
		"./ogl/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.Zip}/src",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.ImPlot}",
		"%{IncludeDir.Lua}",
		"%{IncludeDir.MuParser}",
		"%{IncludeDir.ImGuiNodeEditor}"
	}

	links {
		"opengl32",
		"gdi32",
		"GLFW",
		"Glad",
		"ImGui",
		"ImPlot",
		"ImGuiNodeEditor",
		"ImColorTextEdit",
		"Lua",
		"MuParser",
		"Assimp"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines {
			"TERR3D_WIN32",
			"_NO_CRT_STDIO_INLINE",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines "TERR3D_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "TERR3D_RELEASE"
		optimize "on"	