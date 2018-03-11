#include "renderer.h"

#include "file.h"
#include "logger.h"
#include "shader.h"
#include "texture.h"

#include <glm/ext.hpp>

namespace program {
    GLfloat rotation_angle;
}

Renderer::Renderer(int screen_width, int screen_height) {

    // Initialize shader

    shader_program_ = shader::Load(
            file::Read("shaders/vertex_shader.glsl"),
            file::Read("shaders/fragment_shader.glsl")
    );

    if (shader_program_ == 0) {
        LOG_ERROR("Couldn't create shader program");
        exit(1);
    }

    glUseProgram(shader_program_);

    // Initialize texture

    GLuint texture = texture::LoadPNG(file::Read("textures/illuminati.png"));

    if (texture == 0) {
        LOG_ERROR("Couldn't load texture");
        exit(1);
    }

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Create buffer

    static GLfloat vertices[] = {
            // Position   Texture coordinates
            -0.5f, -0.5f, 0.0f, 0.0f,
            0.5f, -0.5f, 1.0f, 0.0f,
            0.0f, 0.5f, 0.5f, 1.0f
    };

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Initialize vertex array

    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));
    SetScreenSize(screen_width, screen_height);
}

void Renderer::SetScreenSize(int screen_width, int screen_height) {
    auto ratio = static_cast<float>(glm::min(screen_width, screen_height)) / glm::max(screen_width, screen_height);
    if (screen_width < screen_height) {
        coordinate_system_ = glm::vec3(1.0f, ratio, 1.0f);
    } else {
        coordinate_system_ = glm::vec3(ratio, 1.0f, 1.0f);
    }
}


void Renderer::DrawFrame() {
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    auto model = glm::scale(coordinate_system_);
    model = glm::rotate(model, program::rotation_angle, glm::vec3(0, 0, 1));
    glUniformMatrix4fv(glGetUniformLocation(shader_program_, "uModel"), 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 3);

    program::rotation_angle += 0.01;
}

