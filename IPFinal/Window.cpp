//
//  Window.cpp
//  IPFinal
//
//  Created by apple on 2020/1/8.
//  Copyright © 2020 aiofwa. All rights reserved.
//

#include "Window.hpp"
#include <cassert>


Window::Window(std::string title, int w, int h) : windowTitle(title), windowWidth(w), windowHeight(h) {
    
}

void Window::init() { 
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    nativeWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    assert(nativeWindow != nullptr);
    glfwMakeContextCurrent(nativeWindow);
    gladLoadGL();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(nativeWindow);
}

void Window::pollEvents() {
    glfwPollEvents();
}

void Window::swapBuffers() {
    glfwSwapBuffers(nativeWindow);
}
