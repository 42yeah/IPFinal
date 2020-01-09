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
    hardwareCamera.read();
    glWindow = Window("HDR", hardwareCamera.getBufferWidth(), hardwareCamera.getBufferHeight());
    glWindow.init();
    
    // === RENDERERS === //
    camRenderer = CamRenderer();
    camRenderer.init();
    rendererList.push_back(&camRenderer);
    standardProgram.link("Assets/standard.vertex.glsl", "Assets/light.fragment.glsl");
    hdrBuffer.init();
    
    hdrRenderer = HDRRenderer(hardwareCamera.getBufferWidth(), hardwareCamera.getBufferHeight());
    hdrRenderer.init();
    hdrProgram.link("Assets/standard.vertex.glsl", "Assets/hdr.fragment.glsl");
}

void App::start() {
    while (!glWindow.shouldClose()) {
        hardwareCamera.read();
        glWindow.pollEvents();
        if (glWindow.keyPressed(GLFW_KEY_R)) {
            standardProgram.link("Assets/standard.vertex.glsl", "Assets/standard.fragment.glsl");
            hdrProgram.link("Assets/standard.vertex.glsl", "Assets/hdr.fragment.glsl");
        }
        
        // === WRONG RENDERING === //
        hdrBuffer.bind();
        camRenderer.bufferTexture(hardwareCamera.getRawMemory(), (hardwareCamera.getBufferHeight() * hardwareCamera.getBufferWidth()) * 3);
        standardProgram.use();
        standardProgram.setResolution(glm::vec2(hardwareCamera.getBufferWidth(), hardwareCamera.getBufferHeight()));
        camRenderer.render(standardProgram);
        hdrBuffer.unbind();
        
        // === HDR RENDERING === //
        hdrRenderer.setTexture(hdrBuffer);
        hdrRenderer.render(hdrProgram);
        
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
