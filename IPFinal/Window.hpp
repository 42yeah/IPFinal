//
//  Window.hpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp

#include "glad/glad/glad.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <string>


class Window {
public:
    Window() {};
    Window(std::string title, int w, int h);
    
    void init();
    void pollEvents();
    void swapBuffers();

    glm::vec2 getResolution();
    bool shouldClose();
    bool keyPressed(int code);
    
private:
    GLFWwindow *nativeWindow;
    int windowWidth, windowHeight;
    std::string windowTitle;
};

#endif /* Window_hpp */
