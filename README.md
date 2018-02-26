<a href="https://github.com/Codestones/Rebellion-Engine"><img src="Logo.png" align="right" width="120" height="120" alt="Rebellion" title="Rebellion"></a>

# Rebellion Engine
A 3D game engine written in C++ and using OpenGL.

## Table of contents

- [Build](#build)
    - [Requirements](#requirements)
    - [Windows](#windows)
- [Features](#features)
- [Dependencies](#dependencies)
- [License](#license)

## Build
Building the project is currently only possible by using Microsoft Visual Studio (2013 or higher).
In order to build the project you'll need to add the 32-bit [GLFW](http://www.glfw.org/download.html) and [GLEW](http://glew.sourceforge.net/) binaries to the "dependencies" folder.

### Requirements

* C++11
* OpenGL 4.4
* Microsoft Visual Studio 2015

### Windows
Open the "solution file" and build either Debug or Release for Win32.

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

## Dependencies
Name | Description | License
------------ | ------------- | -------------
[Cereal](https://github.com/USCiLab/cereal) | Header-only C++11 serialization library | [BSD](https://opensource.org/licenses/BSD-3-Clause)
[TinyObjLoader](https://github.com/syoyo/tinyobjloader) | Tiny but powerful single file wavefront obj loader | [MIT](https://github.com/syoyo/tinyobjloader/blob/master/LICENSE)
[STB](https://github.com/nothings/stb) | Collection of single-file libraries | [MIT](https://opensource.org/licenses/MIT)
[GLM](https://github.com/g-truc/glm) | OpenGL math library | [MIT](https://github.com/g-truc/glm/blob/master/manual.md#section0)
[IMGUI](https://github.com/ocornut/imgui) | Bloat-free immediate mode graphical user interface | [MIT](https://github.com/ocornut/imgui/blob/master/LICENSE.txt)
[GLFW](https://github.com/glfw/glfw) | Multi-platform library for OpenGL, OpenGL ES, Vulkan, window and input | [ZLIB](https://github.com/glfw/glfw/blob/master/LICENSE.md)
[GLEW](https://github.com/nigels-com/glew) | OpenGL extension wrangler library | [BSD](https://github.com/nigels-com/glew/blob/master/LICENSE.txt), [MESA-3D](http://glew.sourceforge.net/mesa.txt), [Khronos](http://glew.sourceforge.net/khronos.txt)

## License
This project is licensed under the [MIT License](https://github.com/Codestones/Rebellion-Engine/blob/master/LICENSE.md).
Licenses of tools and dependencies are not included and may vary.
