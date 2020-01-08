//
//  Renderer.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include "StandardProgram.hpp"


class Renderer {
public:
    Renderer();
    
    void init();
    void render(StandardProgram standardProgram);
    void bufferTexture(void *buffer, int size);
    
private:
    // === VARIABLES === //
    GLuint VAO, VBO;
    GLuint TBO;
    GLuint dynamicTexture;
};

#endif /* Renderer_hpp */
