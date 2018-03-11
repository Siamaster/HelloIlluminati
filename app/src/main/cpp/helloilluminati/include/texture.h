#pragma once

#include <GLES3/gl3.h>

#include <vector>

namespace texture {
    GLuint LoadPNG(const std::vector<char> &data);
}