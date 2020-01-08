//
//  Renderer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "Renderer.hpp"
#include "glad/glad/glad.h"
#include "Macros.h"


Renderer::Renderer() : TBO(0), dynamicTexture(0) {
    
}

void Renderer::init() { 
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
    glGenVertexArrays(1, &VAO);
    GLuint VBO;
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
    standardProgram.link("Assets/standard.vertex.glsl", "Assets/standard.fragment.glsl");
}

void Renderer::render() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(VAO);
    standardProgram.use();
    standardProgram.configVertexPointers();
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Renderer::bufferTexture(void *buffer, int size) {
    glBindVertexArray(0);
    if (!TBO) {
        glGenBuffers(1, &TBO);
        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        glBufferData(GL_ARRAY_BUFFER, size, buffer, GL_STREAM_DRAW);
    } else {
        glBindBuffer(GL_ARRAY_BUFFER, TBO);
        void *gpuBuffer = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
        std::memcpy(gpuBuffer, buffer, size);
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }
    if (!dynamicTexture) {
        glGenTextures(1, &dynamicTexture);
        glBindTexture(GL_TEXTURE_2D, dynamicTexture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexBuffer(GL_TEXTURE_2D, GL_RGB32UI, GL_TEXTURE_2D);
    }
}
