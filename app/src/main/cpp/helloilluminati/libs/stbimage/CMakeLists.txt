set(SOURCES
        include/stb_image.h
        src/stb_image.cpp)

add_library(stbimage ${SOURCES})

target_include_directories(stbimage PUBLIC include)