cmake_minimum_required(VERSION 3.28)
project(test_module_src)

set(CMAKE_CXX_STANDARD 17)


add_executable(test_module_src main.cpp)

target_include_directories(test_module_src PUBLIC "godot-cpp/include/")
target_include_directories(test_module_src PUBLIC "godot-cpp/gen/include/")
target_include_directories(test_module_src PUBLIC "godot-cpp/gdextension/")

target_include_directories(test_module_src PUBLIC "src/")