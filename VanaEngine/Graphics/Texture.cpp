#include "pch.h"
#include "Texture.h"
#include "Graphics.h"

#include <stb/stb_image.h>

Texture::Texture(char* texturePath)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    // load and generate the texture
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
    GLenum format;
    if (nrChannels == 1)
    {
        format = GL_RED;
        alpha = false;
    }
    else if (nrChannels == 3)
    {
        format = GL_RGB;
        alpha = false;
    }
    else if (nrChannels == 4)
    {
        format = GL_RGBA;
        alpha = true;
    }
    if (data)
    {
        glBindTexture(GL_TEXTURE_2D, ID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

Texture::Texture(const char* texturePath)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
    GLenum format;
    if (nrChannels == 1)
    {
        format = GL_RED;
        alpha = false;
    }
    else if (nrChannels == 3)
    {
        format = GL_RGB;
        alpha = false;
    }
    else if (nrChannels == 4)
    {
        format = GL_RGBA;
        alpha = true;
    }
    if (data)
    {
        glBindTexture(GL_TEXTURE_2D, ID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &ID);
}

void Texture::Bind(int unit)
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

bool Texture::Alpha() const
{
    return alpha;
}
