workspace "Havana"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Havana"
    location "Havana"
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
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HV_PLATFORM_WINDOWS",
            "HV_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "HV_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HV_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
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
        "Havana/vendor/spdlog/include",
        "Havana/src"
    }

    links
    {
        "Havana"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HV_PLATFORM_WINDOWS"
        }
    
    filter "configurations:Debug"
        defines "HV_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HV_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HV_DIST"
        optimize "On"