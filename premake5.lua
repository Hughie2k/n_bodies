workspace "NBodies"
  configurations {
    "Debug"
  }
  location "."

project "Gravity"
  kind "WindowedApp"
  language "C++"
  location "build"
  files {
    "src/*.cpp"
  }
  links {
    "sfml-graphics",
    "sfml-window",
    "sfml-system"
  }
  cppdialect "c++20"
  warnings "extra"