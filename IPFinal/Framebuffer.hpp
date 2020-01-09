//
//  FrameBuffer.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef Framebuffer_hpp
#define Framebuffer_hpp

#include "glad/glad/glad.h"


class Framebuffer {
public:
    Framebuffer();
    
    void init();
    void bind();
    void unbind();
    GLuint getTexture();
    
private:
    GLuint FBO;
    GLuint texture;
};

#endif /* Framebuffer_hpp */
