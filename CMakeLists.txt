# Minimum CMake version
cmake_minimum_required(VERSION 3.1)

# Generated project name
project(Proton)

# C++ standard (C++11)
set(CMAKE_CXX_STANDARD 11)

# Add filters/folders for the generated projects
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Source files
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/source")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")

# Executable definition and properties
file(GLOB SRC
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.cpp"
)

file(GLOB IMGUI
	"${LIB_DIR}/imgui/imgui_internal.h"
	"${LIB_DIR}/imgui/imgui.h"
	"${LIB_DIR}/imgui/imgui.cpp"
	"${LIB_DIR}/imgui/imconfig.h"
	"${LIB_DIR}/imgui/imgui_draw.cpp"
)

add_executable(Proton ${SRC} ${IMGUI})

source_group("imgui" FILES ${IMGUI})

# GLFW
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_link_libraries(${PROJECT_NAME} "glfw" "${GLFW_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLFW_DIR}/include")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# GLAD
set(GLAD_DIR "${LIB_DIR}/glad")
add_subdirectory("${GLAD_DIR}")
target_link_libraries(${PROJECT_NAME} "glad" "${GLAD_LIBRARIES}")
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_BINARY_DIR}/dependencies/glad/include")

# Cereal
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/cereal/include")

# GLM
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glm")

# STB
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/stb")

# Tinyobjloader
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/tinyobjloader")

# Imgui
set(IMGUI_DIR "${LIB_DIR}/imgui")
target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/dependencies/imgui")

# Debugging
message(STATUS "This is the BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is the SOURCE dir " ${PROJECT_SOURCE_DIR})
