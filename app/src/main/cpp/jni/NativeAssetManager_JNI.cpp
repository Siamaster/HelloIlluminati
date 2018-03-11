#include <jni.h>

#include "file.h"

#include <android/asset_manager_jni.h>

#define JNI_FUNCTION(return_type, method_name) extern "C" JNIEXPORT return_type JNICALL Java_com_siamaster_helloilluminati_NativeAssetManager_##method_name

JNI_FUNCTION(void, initialize)(JNIEnv *env, jclass, jobject asset_manager) {
    file::asset_manager = AAssetManager_fromJava(env, asset_manager);
}