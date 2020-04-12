include("conanbuildinfo.premake.lua")

workspace("SFMLExamples")
    architecture "x86_64"
    startproject "Sandbox"
    conan_basic_setup()

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    flags
    {
        "MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ExampleOne"
    location "ExampleOne"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"

    linkoptions { conan_exelinkflags }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.hpp",
	    "%{prj.name}/src/**.cpp"
    }

    includedirs {"%{prj.name}/src"}

    filter "configurations:Debug"
        defines "ONE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "ONE_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "ONE_DIST"
        runtime "Release"
        optimize "on"

project "ExampleTwo"
    location "ExampleTwo"
    kind "ConsoleApp"
    language "C++"
    staticruntime "on"
    
    linkoptions { conan_exelinkflags }
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs {"%{prj.name}/src"}
    
    filter "configurations:Debug"
        defines "TWO_DEBUG"
        runtime "Debug"
        symbols "on"
    
    filter "configurations:Release"
        defines "TWO_RELEASE"
        runtime "Release"
        optimize "on"
    
    filter "configurations:Dist"
        defines "TWO_DIST"
        runtime "Release"
        optimize "on"