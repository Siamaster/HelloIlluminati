set(SOURCE_FILES
        NativeAssetManager_JNI.cpp
        Renderer_JNI.cpp)

add_library(jni SHARED ${SOURCE_FILES})

target_link_libraries(jni android log helloilluminati)