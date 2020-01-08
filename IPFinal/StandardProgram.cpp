//
//  StandardProgram.cpp
//  Snooker3D
//
//  Created by apple on 2019/11/23.
//  Copyright © 2019 aiofwa. All rights reserved.
//

#include "StandardProgram.hpp"
#include <fstream>
#include <sstream>
#include "Macros.h"


StandardProgram::StandardProgram() {
}

void StandardProgram::link(std::string vertexShaderPath, std::string fragmentShaderPath) {
    GLuint program = glCreateProgram();
    glAttachShader(program, compile(GL_VERTEX_SHADER, vertexShaderPath));
    glAttachShader(program, compile(GL_FRAGMENT_SHADER, fragmentShaderPath));
    glLinkProgram(program);
    char log[512];
    glGetProgramInfoLog(program, sizeof(log), nullptr, log);
    LOG("Program: %s", log);
    this->program = program;
    
    // === INITIALIZE LOCATION VARIABLES === //
    cameraTexturePos = glGetUniformLocation(this->program, "cameraTexture");
    resolutionPos = glGetUniformLocation(this->program, "resolution");
}

GLuint StandardProgram::compile(GLuint shaderType, std::string shaderPath) { 
    GLuint shader = glCreateShader(shaderType);
    std::stringstream ss;
    std::ifstream reader(shaderPath);
    ss << reader.rdbuf();
    std::string source = ss.str();
    const char *raw = source.c_str();
    glShaderSource(shader, 1, &raw, nullptr);
    glCompileShader(shader);
    char log[512] = { 0 };
    glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
    LOG("%s: %s", shaderPath.c_str(), log);
    return shader;
}

void StandardProgram::use() {
    glUseProgram(this->program);
}

void StandardProgram::configVertexPointers() {
    this->use();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, nullptr);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void *) (sizeof(float) * 2));
}

void StandardProgram::setCameraTexture(GLuint texture, GLuint TBO) { 
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_BUFFER, texture);
    glTexBuffer(GL_TEXTURE_BUFFER, GL_RGB32UI, TBO);
    glUniform1i(this->cameraTexturePos, 0);
}

void StandardProgram::setResolution(glm::vec2 r) {
    glUniform2f(resolutionPos, r.x, r.y);
}
