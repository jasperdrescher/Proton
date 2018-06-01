<a href="https://github.com/Codestones/Proton"><img src="https://i.imgur.com/HEwdqod.png" align="right" width="120" height="120" alt="Proton" title="Proton"></a>

# Proton <a href="https://github.com/Codestones/Proton/releases"><img src="https://img.shields.io/badge/version-0.0-blue.svg" alt="version" title="version"></a> <a href="https://travis-ci.org/Codestones/Proton"><img src="https://travis-ci.org/Codestones/Proton.svg?branch=master" alt="build status" title="build status"></a>
A cross-platform game engine written in C++ using OpenGL.

## Table of contents
- [Build](#build)
    - [CMake](#cmake)
        - [Requirements](#requirements)
- [Features](#features)
- [Dependencies](#dependencies)
- [License](#license)

## Build
Building this project is made easy using CMake. The project is cross-platform compatible and all dependencies are cloned by Git.

### CMake
To build the project locally you'll need to clone the repository. Depending on your OS you can either use cmake-gui or CMake to generate the project for you. The only prerequisite is [Python](https://www.python.org/), since GLAD uses Python scripts.
It is recommended to build into a `build` folder outside of the source.

#### Requirements
* C++11
* OpenGL 4
* Python 2.7
* CMake 3.1

## Features
* File formats
    * Models
        * [ ] FBX
        * [ ] OBJ
    * Materials
        * [ ] MTL
    * Textures
        * [ ] PNG
        * [ ] JPG
    * Audio
        * [ ] WAV
        * [ ] MP3
 * Parts
    * [ ] Resource manager
    * [ ] Audio manager
    * [ ] Input manager
    * [ ] Shader manager
    * [ ] Scene manager
    * [ ] Scene graph
    * [ ] Renderer
    * [ ] UI
    * [ ] Settings
    * [ ] Serialization
    * [ ] Mathematics
    * [ ] Shaders
    
    

## Dependencies
Name | Description | License
------------ | ------------- | -------------
[Cereal](https://github.com/USCiLab/cereal) | Header-only C++11 serialization library | [BSD](https://opensource.org/licenses/BSD-3-Clause)
[TinyObjLoader](https://github.com/syoyo/tinyobjloader) | Tiny but powerful single file wavefront obj loader | [MIT](https://github.com/syoyo/tinyobjloader/blob/master/LICENSE)
[STB](https://github.com/nothings/stb) | Collection of single-file libraries | [MIT](https://opensource.org/licenses/MIT)
[GLM](https://github.com/g-truc/glm) | OpenGL math library | [MIT](https://github.com/g-truc/glm/blob/master/manual.md#section0)
[IMGUI](https://github.com/ocornut/imgui) | Bloat-free immediate mode graphical user interface | [MIT](https://github.com/ocornut/imgui/blob/master/LICENSE.txt)
[GLFW](https://github.com/glfw/glfw) | Multi-platform library for OpenGL, OpenGL ES, Vulkan, window and input | [ZLIB](https://github.com/glfw/glfw/blob/master/LICENSE.md)
[GLAD](https://github.com/Dav1dde/glad) | Multi-Language GL Loader-Generator | [MIT](https://github.com/Dav1dde/glad/blob/master/LICENSE)

## License
This project is licensed under the [MIT License](https://github.com/Codestones/Proton/blob/master/LICENSE.md).
Licenses of tools and dependencies are not included and may vary.
