#include <jni.h>

#include "renderer.h"

#define JNI_FUNCTION(return_type, method_name) extern "C" JNIEXPORT return_type JNICALL Java_com_siamaster_helloilluminati_Renderer_##method_name
#define THIS ((Renderer *)env->GetLongField(obj, native_handle))

static jfieldID native_handle;

JNI_FUNCTION(void, classInit)(JNIEnv *env, jclass clazz) {
    native_handle = env->GetFieldID(clazz, "mNativeHandle", "J");
}

JNI_FUNCTION(void, destroy)(JNIEnv *env, jobject obj) {
    delete THIS;
}

JNI_FUNCTION(jlong, create)(JNIEnv *, jobject) {
    return jlong(new Renderer);
}

JNI_FUNCTION(void, setSize)(JNIEnv *env, jobject obj, jint width, jint height) {
    THIS->SetScreenSize(width, height);
}

JNI_FUNCTION(void, drawFrame)(JNIEnv *env, jobject obj) {
    THIS->DrawFrame();
}