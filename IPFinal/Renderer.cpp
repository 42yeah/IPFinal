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


Renderer::Renderer() : TBO(0) {
    
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

}

