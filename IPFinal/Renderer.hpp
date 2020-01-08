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


class IRenderer {
public:
    IRenderer() {};
    
    virtual void init() = 0;
    virtual void render(StandardProgram &standardProgram) = 0;
};

class CamRenderer : public IRenderer {
public:
    CamRenderer();
    
    virtual void init() override;
    virtual void render(StandardProgram &standardProgram) override;
    void bufferTexture(void *buffer, int size);
    
private:
    // === VARIABLES === //
    GLuint VAO, VBO;
    GLuint TBO;
    GLuint dynamicTexture;
};

#endif /* Renderer_hpp */
