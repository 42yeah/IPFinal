//
//  FrameBuffer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "Framebuffer.hpp"


Framebuffer::Framebuffer() : texture(0), FBO(0) {
}

void Framebuffer::init() {
    glGenFramebuffers(1, &FBO);
}

void Framebuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
}

void Framebuffer::unbind() { 
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
