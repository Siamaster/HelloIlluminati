package com.siamaster.helloilluminati;

import android.app.Application;

public class HelloIlluminati extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        NativeAssetManager.initialize(getAssets());
    }
}
