//
//  CamRenderer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "CamRenderer.hpp"
#include "glad/glad/glad.h"
#include "Macros.h"


CamRenderer::CamRenderer() : TBO(0), dynamicTexture(0) {
    
}

void CamRenderer::init() {
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    float data[] = {
        /* aPos */ /* Texture UV */
        -1.0f, -1.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f, 0.0f
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
}

void CamRenderer::render(StandardProgram &standardProgram) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    standardProgram.use();
    standardProgram.setCameraTexture(dynamicTexture, TBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    standardProgram.configVertexPointers();
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void CamRenderer::bufferTexture(void *buffer, int size) {
    if (!TBO) {
        glGenBuffers(1, &TBO);
        glBindBuffer(GL_TEXTURE_BUFFER, TBO);
        glBufferData(GL_TEXTURE_BUFFER, size, buffer, GL_STREAM_DRAW);
    } else {
        glBindBuffer(GL_TEXTURE_BUFFER, TBO);
        void *gpuBuffer = glMapBuffer(GL_TEXTURE_BUFFER, GL_WRITE_ONLY);
        std::memcpy(gpuBuffer, buffer, size);
        glUnmapBuffer(GL_TEXTURE_BUFFER);
    }
    if (!dynamicTexture) {
        glGenTextures(1, &dynamicTexture);
        glBindTexture(GL_TEXTURE_BUFFER, dynamicTexture);
        // ARRAY BUFFER...
    }
}
