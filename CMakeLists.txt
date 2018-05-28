# Minimum CMake version
cmake_minimum_required(VERSION 3.1)

# Generated project name
project(Proton)

# C++ standard (C++11)
set(CMAKE_CXX_STANDARD 11)

# Add filters/folders for the generated projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Source files
set(SRC_DIR_2D "${CMAKE_CURRENT_SOURCE_DIR}/source/2D")
set(SRC_DIR_3D "${CMAKE_CURRENT_SOURCE_DIR}/source/3D")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

# Executable definition and properties
file(GLOB_RECURSE SRC_2D
    "${SRC_DIR_2D}/*.h"
    "${SRC_DIR_2D}/*.cpp"
)

file(GLOB_RECURSE SRC_3D
    "${SRC_DIR_3D}/*.h"
    "${SRC_DIR_3D}/*.cpp"
)

file(GLOB IMGUI
	"${LIB_DIR}/imgui/imgui_internal.h"
	"${LIB_DIR}/imgui/imgui.h"
	"${LIB_DIR}/imgui/imgui.cpp"
	"${LIB_DIR}/imgui/imconfig.h"
	"${LIB_DIR}/imgui/imgui_draw.cpp"
)

add_executable(Proton2D ${SRC_2D} ${IMGUI})
add_executable(Proton3D ${SRC_3D} ${IMGUI})

source_group("imgui" FILES ${IMGUI})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(Proton2D "glfw" "${GLFW_LIBRARIES}")
target_include_directories(Proton2D PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(Proton2D PRIVATE "GLFW_INCLUDE_NONE")
target_link_libraries(Proton3D "glfw" "${GLFW_LIBRARIES}")
target_include_directories(Proton3D PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(Proton3D PRIVATE "GLFW_INCLUDE_NONE")

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_subdirectory("${GLAD_DIR}")
target_link_libraries(Proton2D "glad" "${GLAD_LIBRARIES}")
target_include_directories(Proton2D PRIVATE "${PROJECT_BINARY_DIR}/dependencies/glad/include")
target_link_libraries(Proton3D "glad" "${GLAD_LIBRARIES}")
target_include_directories(Proton3D PRIVATE "${PROJECT_BINARY_DIR}/dependencies/glad/include")

# Cereal
target_include_directories(Proton2D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/cereal/include")
target_include_directories(Proton3D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/cereal/include")

# GLM
target_include_directories(Proton2D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm")
target_include_directories(Proton3D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm")

# STB
target_include_directories(Proton2D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb")
target_include_directories(Proton3D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb")

# Tinyobjloader
target_include_directories(Proton3D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/tinyobjloader")

# Imgui
set(IMGUI_DIR "${LIB_DIR}/imgui")
target_include_directories(Proton2D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/imgui")
target_include_directories(Proton3D PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/imgui")

# Debugging
message(STATUS "This is the BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is the SOURCE dir " ${PROJECT_SOURCE_DIR})
