//
//  App.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "App.hpp"
#include <opencv2/opencv.hpp>
#include "Macros.h"


void App::init() { 
    hardwareCamera = Camera(0);
    glWindow = Window("GL Window", 800, 600);
    glWindow.init();
    glRenderer = Renderer();
    glRenderer.init();
    standardProgram.link("Assets/standard.vertex.glsl", "Assets/standard.fragment.glsl");
}

void App::start() {
    while (!glWindow.shouldClose()) {
        hardwareCamera.read();
        glWindow.pollEvents();
        if (glWindow.keyPressed(GLFW_KEY_R)) {
            LOG("Relinking...");
            standardProgram.link("Assets/standard.vertex.glsl", "Assets/standard.fragment.glsl");
        }
        glRenderer.bufferTexture(hardwareCamera.getRawMemory(), (hardwareCamera.getBufferHeight() * hardwareCamera.getBufferWidth()) * 3);
        standardProgram.use();
        standardProgram.setResolution(glm::vec2(hardwareCamera.getBufferWidth(), hardwareCamera.getBufferHeight()));
        glRenderer.render(standardProgram);
        glWindow.swapBuffers();
    }
}

void App::testRawMemory() {
    hardwareCamera.read();
    char *buffer = (char *) hardwareCamera.getRawMemory();
    for (int i = 0; i < hardwareCamera.getBufferHeight(); i++) {
        for (int j = 0; j < hardwareCamera.getBufferWidth(); j++) {
            int offset = (i * hardwareCamera.getBufferWidth() + j) * 3;
            LOG("[%d, %d, %d]", (unsigned int) buffer[offset + 0], (unsigned int) buffer[offset + 1], (unsigned int) buffer[offset + 2]);
        }
    }
}
