//
//  Renderer.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "IRenderer.hpp"


void IRenderer::renderToFrameBuffer(StandardProgram &standardProgram, Framebuffer &fbo) {
    fbo.bind();
    render(standardProgram);
    fbo.unbind();
}
