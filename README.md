<br/>
<p align="center">
    <img src="https://raw.githubusercontent.com/Jaysmito101/ogl/master/ReadmeHeader.gif" border="0"></
</p>

<br/>
<p align="center">
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/Jaysmito101/ogl?style=for-the-badge">
  <img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/Jaysmito101/ogl?style=for-the-badge">
  <img alt="GitHub commit activity" src="https://img.shields.io/github/commit-activity/w/Jaysmito101/ogl?style=for-the-badge">
    <br>
    <img alt="Maintenance" src="https://img.shields.io/maintenance/yes/2022?style=for-the-badge">
    <a href="https://patreon.com/jaysmito101"><img src="https://img.shields.io/endpoint.svg?url=https%3A%2F%2Fshieldsio-patreon.vercel.app%2Fapi%3Fusername%3Djaysmito101%26type%3Dpledges&style=for-the-badge" alt="Support me on Patreon" /></a>
</p>
<br/>


# ogl
OGL - A Great Cross Platform OpenGL Base Library With Everything You might Ever need!

For any Questions : https://discord.gg/vYFeWXUZ7A

NOTE : The code in this repository is based on [TerraForge3D](https://github.com/Jaysmito101/TerraForge3D).

# How to use?

This is made with only one thing in mind : Ease Of Use!
This is to be used as a git subbmodule!

So Lets Create a new Project step by step!

    mkdir Project
    cd Project
    git init
    git submodule add https://github.com/Jaysmito101/ogl.git

Now you have sucessfully added OGL to your Project! (A ```ogl``` folder created)
Now, OGL privides a sample project for us to ork upon!
To Get Started with the sample project:

 * Copy the ```MyProject``` folder from ```ogl``` folder to the main folder
 * Copy the ```premake5.lua``` from ```ogl``` folder to the main folder
 
Now we need to Generate Our Project files!

### For Windows

    ogl\premake\premake5 msvc19

Done A MySolution.sln will be generated Just open it up with Visual Studio!

### For Linux

    ./ogl/premake/premake5 gmake

This will generate the ```Makefile```s.

To Build:

    make CC=gcc
    
## What does OGL Provide?

OGL provides access to the following libraries:

 * [assimp](https://github.com/assimp/assimp)
 * [avir](https://github.com/avaneev/avir)
 * [dirent](https://github.com/tronkko/dirent)
 * [glad](https://github.com/Dav1dde/glad)
 * [glfw](https://github.com/glfw/glfw)
 * [glm](https://github.com/Groovounet/glm)
 * [hdritocubemap](https://github.com/ivarout/HdriToCubemap)
 * [imgui](https://github.com/ocornut/imgui)
 * [imgui-node-editor](https://github.com/thedmd/imgui-node-editor)
 * [implot](https://github.com/epezent/implot)
 * [lua](https://github.com/lua/lua)
 * [muparser](https://github.com/beltoforion/muparser)
 * [stb](https://github.com/nothings/stb)
 * [imguicolortextedit](https://github.com/BalazsJako/ImGuiColorTextEdit)
 * [tinyerode](https://github.com/tay10r/TinyErode)

Along with all this libraries you have access to the powerful ```ogl-core```
It provides abstractions for most of OpenGL needs:

 * EntryPoint
 * Setting Up Context for Imgui, ... other frameworks
 * Window Creation and management
 * Camera
 * Vertex, Fragment, Geometry Shaders
 * Compute Shaders
 * Textures
 * FrameBuffers
 * Special ImGui Widgets
 * 3D Mesh Importers
 * Mesh renderers
 * Abstracted 3D Mesh, Model Data Structure
 * SSBOs (Shader Storage Buffer Objects)
 * Font Manager
 * Cubemaps
