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
};

#endif /* App_hpp */