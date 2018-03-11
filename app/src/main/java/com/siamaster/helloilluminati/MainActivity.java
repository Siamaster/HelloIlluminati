package com.siamaster.helloilluminati;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;

public class MainActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        GLSurfaceView surfaceView = findViewById(R.id.gl_view);
        surfaceView.setEGLConfigChooser(8, 8, 8, 0, 16, 0);
        surfaceView.setEGLContextClientVersion(3);
        Renderer renderer = new Renderer();
        surfaceView.setRenderer(renderer);
        surfaceView.getHolder().addCallback(renderer);
    }
}
