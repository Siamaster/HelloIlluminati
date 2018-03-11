package com.siamaster.helloilluminati;

import android.opengl.GLSurfaceView;
import android.view.SurfaceHolder;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class Renderer implements SurfaceHolder.Callback, GLSurfaceView.Renderer {

    static {
        System.loadLibrary("jni");
        classInit();
    }

    private long mNativeHandle; // Accessed from JNI

    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {
        // Don't create Renderer here. OpenGL Context has not yet been created.
    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int format, int width, int height) {
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {
        destroy();
        mNativeHandle = 0;
    }

    @Override
    public void onSurfaceCreated(GL10 gl10, EGLConfig eglConfig) {
        mNativeHandle = create();
    }

    @Override
    public void onSurfaceChanged(GL10 gl10, int width, int height) {
        if (mNativeHandle == 0) {
            // This is due to a bug from Android. Pressing Home calls surfaceDestroyed but coming back calls
            // onSurfaceChanged twice instead of first calling onSurfaceCreated
            mNativeHandle = create();
        }
        setSize(width, height);
    }
    @Override
    public void onDrawFrame(GL10 gl10) {
        drawFrame();
    }

    private native void destroy();
    private native long create();
    private native void setSize(int width, int height);
    private native void drawFrame();
    private native static void classInit();
}
