//
//  HDRRenderer.hpp
//  IPFinal
//
//  Created by apple on 2020/1/9.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef HDRRenderer_hpp
#define HDRRenderer_hpp

#include "IRenderer.hpp"
#include "StandardProgram.hpp"
#include "Framebuffer.hpp"


class HDRRenderer : public IRenderer {
public:
    HDRRenderer() {}
    HDRRenderer(int w, int h);
    
    virtual void init() override;
    virtual void render(StandardProgram &standardProgram) override;
    void setTexture(Framebuffer &buffer);
    
private:
    // === VARIABLES === //
    int textureWidth, textureHeight;
    GLuint VAO;
    GLuint dynamicTexture;
};

#endif /* HDRRenderer_hpp */
