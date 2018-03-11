#pragma once

#include <GLES3/gl3.h>

#include <vector>

namespace shader {
    GLuint Load(const std::vector<char> &vertex_source,const std::vector<char> &fragment_source);
}