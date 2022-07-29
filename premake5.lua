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
<<<<<<< HEAD
  includedirs {"../../SFML-2.5.1/include"}
  libdirs {"../../SFML-2.5.1/lib"}
=======
  cppdialect "c++20"
  warnings "extra"
>>>>>>> 38b09420a773450a4b7507259bd0c6838089136d
