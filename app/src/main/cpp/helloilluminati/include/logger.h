#pragma once

#ifdef ANDROID

#include <android/log.h>

#define LOG_ERROR(...) __android_log_print(ANDROID_LOG_ERROR, "OpenGLTest", __VA_ARGS__)

#else

#include <cstdio>

#define LOG_ERROR(...) printf(__VA_ARGS__); printf("\n"); std::fflush(stdout);

#endif