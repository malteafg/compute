# C++/Kompute
This folder contains examples of using the Kompute library in C++ to execute code on the GPU.

## Setup
* Make sure the vulkan SDK is installed somewhere on your system. Vulkan is needed to build Kompute.
  * The vulkan SDK can typically be sourced (activated) using ```source
    <path_to_vulkan_sdk>/setup-env.sh```.
* Kompute also needs to be installed.
  * These examples use Kompute v0.9.0 which can be found on their GitHub release pages
    [Kompute0.9.0](https://github.com/KomputeProject/kompute/releases/tag/v0.9.0)
  * The examples are currently setup to compile Kompute from source. Look in the CMakeLists.txt file
    to see the expected path of the Kompute repository. Optionally, change the CMakeLists.txt file
    to fit with however you install Kompute.
* The compute shader is compiled to SPIR-V using ```glslangValidator```. Make sure it is installed
  on your pc.

## Running examples
* Use ```make <example>``` to run the given example.

## Cleanup
* To clean auxiliary files that examples may generate use ```make clean```
