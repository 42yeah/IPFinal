//
//  App.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef App_hpp
#define App_hpp

#include "CamFetch.hpp"
#include "Window.hpp"
#include "CamRenderer.hpp"
#include "HDRRenderer.hpp"


class App {
public:
    App() {}
    
    // === METHODS === //
    void init();
    void start();
    
    // === TESTS === //
    void testRawMemory();
    
private:
    // === VARIABLES === //
    Camera hardwareCamera;
    Window glWindow;
    
    std::vector<IRenderer *> rendererList;
    
    // === WAY-TO-LIGHT (OR DARK) CAM === //
    CamRenderer camRenderer;
    StandardProgram standardProgram;
    Framebuffer hdrBuffer; // Which means this is to be taken to HDR post-processing
    
    // === HDR RENDERER === //
    HDRRenderer hdrRenderer;
    StandardProgram hdrProgram;
};

#endif /* App_hpp */
