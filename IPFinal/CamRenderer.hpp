//
//  CamRenderer.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef CamRenderer_hpp
#define CamRenderer_hpp

#include "StandardProgram.hpp"
#include "Renderer.hpp"

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

#endif /* CamRenderer_hpp */
