//
//  FramebufferRenderer.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef FramebufferRenderer_hpp
#define FramebufferRenderer_hpp

#include "IRenderer.hpp"
#include "Framebuffer.hpp"
#include <vector>


class FramebufferRenderer : public IRenderer {
public:
    FramebufferRenderer() {};
    
    virtual void init() override;
    virtual void render(StandardProgram &standardProgram) override;
    void setFramebufferList(std::vector<Framebuffer *> list);
    
private:
    std::vector<Framebuffer *> framebufferList;
};

#endif /* FramebufferRenderer_hpp */
