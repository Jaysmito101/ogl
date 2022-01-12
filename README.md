# ogl
OGL - A Great Cross Platform OpenGL Base Library With Everything You might Ever need!

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

 * [assimp]()
 * [avir]()
 * [dirent]()
 * [glad]()
 * [glfw]()
 * [glm]()
 * [hdritocubemap]()
 * [imgui]()
 * [imgui-node-editor]()
 * [implot]()
 * [lua]()
 * [muparser]()
 * [stb]()
 * [imguicolortextedit]()
 * [tinyerode]()

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
