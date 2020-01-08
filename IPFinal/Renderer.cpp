//
//  Renderer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "Renderer.hpp"
#include "glad/glad/glad.h"


void Renderer::init() { 
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
}

void Renderer::render() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
