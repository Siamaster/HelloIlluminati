#include "texture.h"

#include <stb_image.h>

namespace texture {

    GLuint LoadPNG(const std::vector<char> &data) {
        GLuint texture;
        glGenTextures(1, &texture);

        stbi_set_flip_vertically_on_load(1);
        int width, height, channels;
        auto image = stbi_load_from_memory((const stbi_uc *) data.data(), sizeof(char) * data.size(), &width, &height, &channels, 0);

        if (image == nullptr) {
            return 0;
        }

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(image);
        return texture;
    }

} // namespace texture