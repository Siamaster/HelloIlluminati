cmake_minimum_required(VERSION 3.4.1)

set(ANDROID ON)
add_definitions(-DANDROID)
# Will copy shaders and textures to this folder
set(ASSETS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/main/assets)

add_subdirectory(src/main/cpp/helloilluminati)
add_subdirectory(src/main/cpp/jni)
