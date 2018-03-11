#include "shader.h"

#include "logger.h"

namespace shader {

    static const int kBufferSize = 512;

    GLuint Compile(const std::vector<char> &source, GLenum shader_type) {
        GLuint shader = glCreateShader(shader_type);
        const char* char_ptr_source = &source[0];
        glShaderSource(shader, 1, &char_ptr_source, nullptr);
        glCompileShader(shader);
        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (success == 0) {
            char info[kBufferSize];
            glGetShaderInfoLog(shader, kBufferSize, nullptr, (GLchar *) info);
            LOG_ERROR("Shader error: %s", info);
            return 0;
        }
        return shader;
    }

    GLuint Link(GLuint vertex_shader, GLuint fragment_shader) {
        GLuint program = glCreateProgram();
        glAttachShader(program, vertex_shader);
        glAttachShader(program, fragment_shader);
        glLinkProgram(program);
        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (success == 0) {
            char info[kBufferSize];
            glGetShaderInfoLog(program, kBufferSize, nullptr, (GLchar *) info);
            LOG_ERROR("Shader error: %s", info);
            return 0;
        }
        return program;
    }

    GLuint Load(const std::vector<char> &vertex_source, const std::vector<char> &fragment_source) {
        GLuint vertex_shader = Compile(vertex_source, GL_VERTEX_SHADER);
        if (vertex_shader == 0) {
            LOG_ERROR("Failed to compile vertex shader");
            return 0;
        }

        GLuint fragment_shader = Compile(fragment_source, GL_FRAGMENT_SHADER);
        if (fragment_shader == 0) {
            LOG_ERROR("Failed to compile fragment shader");
            glDeleteShader(vertex_shader);
            return 0;
        }

        GLuint program = Link(vertex_shader, fragment_shader);

        if (program == 0) {
            LOG_ERROR("Failed to link program");
        }

        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);

        return program;
    }
} // namespace shader
