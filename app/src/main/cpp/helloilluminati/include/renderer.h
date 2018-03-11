#pragma once

#ifdef ANDROID

#include <EGL/egl.h>

#else

#include <GL/gl.h>

#endif

#include <GLES3/gl3.h>
#include <glm/glm.hpp>

class Renderer {
public:

    Renderer(int screen_width = 0, int screen_height = 0);

    void SetScreenSize(int screen_width, int screen_height);

    void DrawFrame();

private:

    GLuint shader_program_ = 0;
    glm::vec3 coordinate_system_{};
};
