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
  includedirs {"../../SFML-2.5.1/include"}
  libdirs {"../../SFML-2.5.1/lib"}