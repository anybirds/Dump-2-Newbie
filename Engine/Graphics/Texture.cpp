#include <iostream>

#include <SOIL/SOIL.h>

#include <iostream>

#include <Graphics/Texture.hpp>

using namespace std;
using namespace Engine;

namespace Engine {
    TYPE_DEF(Texture)
    SER_DEF(Texture, Resource,
    MEMBER_SER | MEMBER_SHOW, std::string, path
    )
}

Texture::Texture(const string &name, Type *type) : Resource(name, type) {

}

void Texture::OnInit() {
    int width, height, channel;
    unsigned char *image = SOIL_load_image(path.c_str(), &width, &height, &channel, SOIL_LOAD_AUTO);
    if (!image) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " cannot load image file: " << texture_path << '\n';
#endif
        throw exception();
    }

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);

    Resource::OnInit();
}

void Texture::OnDestroy() {
    glDeleteTextures(1, &id);
    Resource::OnDestroy();
}
