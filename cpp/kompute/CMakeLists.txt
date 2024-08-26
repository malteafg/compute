cmake_minimum_required(VERSION 3.11.0)
project(cpp_kompute_examples VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../../../../libs/kompute-0.9.0/ ${CMAKE_CURRENT_BINARY_DIR}/kompute_build)

# option(KOMPUTE_OPT_GIT_TAG "The tag of the repo to use for the example" v0.9.0)
# include(FetchContent)
# FetchContent_Declare(kompute GIT_REPOSITORY https://github.com/KomputeProject/kompute.git GIT_TAG ${KOMPUTE_OPT_GIT_TAG})
# FetchContent_MakeAvailable(kompute)
# include_directories(${kompute_SOURCE_DIR}/src/include)


add_executable(basic basic/basic.cpp)
target_link_libraries(basic PRIVATE kompute::kompute)
