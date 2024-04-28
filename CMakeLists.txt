cmake_minimum_required(VERSION 3.28)
project(GDExtension_Template)

set(CMAKE_CXX_STANDARD 17)


add_executable(src main.cpp)

target_include_directories(src PUBLIC "godot-cpp/include/")
target_include_directories(src PUBLIC "godot-cpp/gen/include/")
target_include_directories(src PUBLIC "godot-cpp/gdextension/")

target_include_directories(src PUBLIC "src/")