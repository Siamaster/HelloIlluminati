package com.siamaster.helloilluminati;

import android.content.res.AssetManager;

public class NativeAssetManager {

    static {
        System.loadLibrary("jni");
    }

    public native static void initialize(AssetManager assetManager);
}
