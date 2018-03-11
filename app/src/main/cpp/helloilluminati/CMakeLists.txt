#CLion entry point
if (NOT ANDROID)
    cmake_minimum_required(VERSION 3.9)
    set(CMAKE_CXX_STANDARD 14)
    set(ASSETS_DIRECTORY ${CMAKE_BINARY_DIR}/assets)
    add_definitions(-DASSETS_DIRECTORY=\"assets/\")
    add_subdirectory(libs/glfw)
endif ()

add_subdirectory(libs/glm)
add_subdirectory(libs/stbimage)

set(SOURCE_FILES
        include/file.h
        include/logger.h
        include/renderer.h
        include/shader.h
        include/texture.h
        src/file.cpp
        src/renderer.cpp
        src/shader.cpp
        src/texture.cpp)

if (ANDROID)
    add_library(helloilluminati ${SOURCE_FILES})
    target_link_libraries(helloilluminati EGL GLESv3)
else ()
    add_executable(helloilluminati main.cpp ${SOURCE_FILES})
    target_link_libraries(helloilluminati GL glfw)
endif ()

target_link_libraries(helloilluminati glm stbimage)
target_include_directories(helloilluminati PUBLIC include)

add_custom_target(ALWAYS_DO_POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSETS_DIRECTORY}/shaders
        COMMAND cp shaders/* ${ASSETS_DIRECTORY}/shaders/
        COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSETS_DIRECTORY}/textures
        COMMAND cp textures/* ${ASSETS_DIRECTORY}/textures/
        COMMAND ${CMAKE_COMMAND} -E touch .always_do_post_build.h
        COMMAND ${CMAKE_COMMAND} -E echo \"// Hack to always perform a post build operation\" > .always_do_post_build.h
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_dependencies(helloilluminati ALWAYS_DO_POST_BUILD)