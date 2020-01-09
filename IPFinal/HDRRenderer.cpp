//
//  HDRRenderer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/9.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "HDRRenderer.hpp"


HDRRenderer::HDRRenderer(int w, int h) : dynamicTexture(0), textureWidth(w), textureHeight(h) {
}

void HDRRenderer::init() {
    glGenTextures(1, &dynamicTexture);
    glBindTexture(GL_TEXTURE_2D, dynamicTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, textureWidth, textureHeight, 0, GL_RGBA, GL_FLOAT, nullptr);
}

void HDRRenderer::render(StandardProgram &standardProgram) {
    // TODO;
}

void HDRRenderer::setTexture(Framebuffer &buffer) {
    glBindTexture(GL_TEXTURE_2D, dynamicTexture);
    buffer.bind();
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, dynamicTexture, 0);
    buffer.unbind();
}
