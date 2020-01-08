//
//  Window.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include <GLFW/glfw3.h>
#include <string>


class Window {
public:
    Window() {};
    Window(std::string title, int w, int h);
    
    void init();
    void pollEvents();
    bool shouldClose();
    void swapBuffers();
    
private:
    GLFWwindow *nativeWindow;
    int windowWidth, windowHeight;
    std::string windowTitle;
};

#endif /* Window_hpp */
