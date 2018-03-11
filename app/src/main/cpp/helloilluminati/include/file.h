#pragma once

#ifdef ANDROID

#include <android/asset_manager_jni.h>

#endif

#include <vector>

namespace file {

#ifdef ANDROID

    extern AAssetManager *asset_manager;

#endif

    std::vector<char> Read(const char *path);
}